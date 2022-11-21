#ifndef sisaltoa_H
#define sisaltoa_H

#include <QDialog>


QT_BEGIN_NAMESPACE
namespace Ui { class Sisaltoa; }
QT_END_NAMESPACE

class Sisaltoa : public QDialog
{
    Q_OBJECT

public:
    Sisaltoa(QWidget *parent = nullptr);
    ~Sisaltoa();

private:
    Ui::Sisaltoa *ui;

private slots:

};

#endif // sisaltoa_H
