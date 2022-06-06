#pragma once
#include <QObject>
#include <QString>

struct Product{
    Q_GADGET




    Q_PROPERTY(int id MEMBER m_id)
    Q_PROPERTY(int calories MEMBER m_calories)
    Q_PROPERTY(QString name MEMBER m_name)

public:



    int m_id;
    int m_calories;

    QString m_name;

};

Q_DECLARE_METATYPE(Product);


