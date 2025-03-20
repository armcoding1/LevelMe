#include "app_initializer.h"
#include <QStandardPaths>
#include <QDir>
#include "bcrypt.h"

app_initializer::app_initializer()
    :LevelMe_dir(QStandardPaths::writableLocation(QStandardPaths::HomeLocation)),
    db_manager(LevelMe_dir + "/documents/LevelMeData/level_me.db") {};


app_initializer::~app_initializer() {};

bool app_initializer::initialize()
{
    return setup_directories() && setup_database();
}

bool app_initializer::setup_directories()
{
    QDir dir(LevelMe_dir);
    return dir.exists() || dir.mkpath(".");
}

bool app_initializer::setup_database()
{
    if(!db_manager.open_database())
    {
        return false;
    }
    db_manager.create_users_table();
    insert_default_user();
    return true;
}

void app_initializer::insert_default_user()
{
    QString password = "root";
    std::string hash_std = bcrypt::generateHash(password.toStdString());
    QString hashed_password = QString::fromStdString(hash_std);

    db_manager.insert_user(
        "admin@gmail.com",
        hashed_password,
        "root", "root",
        18,
        "",
        "", ""
    );
}
