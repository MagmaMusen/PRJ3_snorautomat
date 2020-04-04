#ifndef TEKST2_H
#define TEKST2_H

#include <QWidget>

class tekst2 : public QWidget
{
    Q_OBJECT
public:
    explicit tekst2(QWidget *parent = nullptr);
    void print();

signals:
    void valueChanged(int);

private:
    char tekst_;

public slots:

};

#endif // TEKST2_H
