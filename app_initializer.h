#ifndef APP_INITIALIZER_H
#define APP_INITIALIZER_H

#include <QString>
#include "database_manager.h"

class app_initializer
{
public:
    app_initializer();
    ~app_initializer();
    bool initialize();
private:
    QString LevelMe_dir;
    database_manager db_manager;

    bool setup_directories();
    bool setup_database();
    void insert_default_user();
};

#endif
