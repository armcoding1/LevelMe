#ifndef DATABASE_MANAGER_H
#define DATABASE_MANAGER_H

#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class database_manager
{
public:
    database_manager(const QString &db_path);
    ~database_manager();
    bool open_database();
    bool create_users_table();
    void insert_user(
        const QString &email,
        const QString &password,
        const QString &first_name,
        const QString &last_name,
        int age,
        const QString &hobbies,
        const QString &habits,
        const QString &skills
    );

private:
    QSqlDatabase db;
};

#endif
