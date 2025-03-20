#include "database_manager.h"

database_manager::database_manager(const QString &db_path)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(db_path);
}

database_manager::~database_manager()
{
    db.close();
}

bool database_manager::open_database()
{
    try {
        if(!db.open())
        {
            qCritical() << "Error Connecting To Database:" << db.lastError().text();
            return false;
        }
        qDebug() << "Connected Successfully!";
        return true;
    } catch (const std::runtime_error &e) {
        qCritical() << "Error:" << e.what();
        return false;
    }
}

bool database_manager::create_users_table()
{
    QSqlQuery query;
    QString query_text = "CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY, email TEXT, password TEXT, first_name TEXT, last_name TEXT, age INTEGER, hobbies TEXT, habits TEXT, skills TEXT)";

    try {
        if(!query.exec(query_text)){
            qCritical() << "Error Creating Table:" << query.lastError().text();
            return false;
        }
        return true;
    } catch (const std::runtime_error &e) {
        qCritical() << "Error:" << e.what();
        return false;
    }
}

void database_manager::insert_user(
    const QString &email,
    const QString &password,
    const QString &first_name,
    const QString &last_name,
    int age,
    const QString &hobbies,
    const QString &habits,
    const QString &skills
    )
{
    QSqlQuery query;
    QString query_text = "INSERT INTO users (email, password, first_name, last_name, age, hobbies, habits, skills) VALUES (?, ?, ?, ?, ?, ?, ?, ?)";

    query.prepare(query_text);

    query.addBindValue(email);
    query.addBindValue(password);
    query.addBindValue(first_name);
    query.addBindValue(last_name);
    query.addBindValue(age);
    query.addBindValue(hobbies);
    query.addBindValue(habits);
    query.addBindValue(skills);

    if(!query.exec())
    {
        qCritical() << "Error Inserting User:" << query.lastError().text();
        return;
    }
}
