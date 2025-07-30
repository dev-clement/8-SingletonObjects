#ifndef MYSINGLETON_HPP
#define MYSINGLETON_HPP

#include <QObject>
#include <QDebug>
#include <QtQml>

class MySingleton : public QObject
{
    Q_OBJECT
    // QML_SINGLETON
    // QML_ELEMENT
public:
    explicit MySingleton(QObject *parent = nullptr);

    // Invokable method
    Q_INVOKABLE void doSomething() const {
        qDebug() << "Doing something...";
    }
signals:
};

#endif // MYSINGLETON_HPP
