#ifndef ACTIONSTADE_H
#define ACTIONSTADE_H
#include <QtSql>
#include <QString>
class ActionStade
{
public:
    ActionStade();
    int idP;
    int id;
    QString Text;
    QString d1_Text;
    QString d2_Text;
    QString d3_Text;
    int d1_Key;
    int d2_Key;
    int d3_Key;
    bool Died;

    void GetFromDB(int a)
    {
        QString b;
        b.setNum(a);
        QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE", "SQLITE");
        db.setDatabaseName("C:/qt_creator/MyProjectQ_2/myproject.db");
        bool ok=db.open();
        if(!ok)
        {
            // throw tr("Cannot open database");
        }
        else
        {
            QSqlQuery query(db);
            query.exec("SELECT * FROM QuestionState WHERE id="+b);
            while (query.next())
            {
                idP = query.value(0).toInt();
                id = query.value(1).toInt();
                Text = query.value(2).toString();
                d1_Text = query.value(3).toString();
                d2_Text = query.value(4).toString();
                d3_Text = query.value(5).toString();
                d1_Key = query.value(6).toInt();
                d2_Key = query.value(7).toInt();
                d3_Key = query.value(8).toInt();
                Died = query.value(9).toBool();
            }

        }

        db.close();
    }


};

#endif // ACTIONSTADE_H
