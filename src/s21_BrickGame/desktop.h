#ifndef DESKTOP_H
#define DESKTOP_H

#include <qt6/QtWidgets/QMainWindow>
#include <qt6/QtWidgets/QFileDialog>
#include <qt6/QtGui/QPixmap>
#include "mywidget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void updateStatusBar(QString &fileName, int vertexCount, int surfaceCount);
    void on_action_triggered();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_comboBox_2_currentIndexChanged(int index);

    void on_spinBox_10_valueChanged(int arg1);

    void on_comboBox_3_currentIndexChanged(int index);

    void on_pushButton_2_clicked();

    void on_spinBox_11_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
    MyWidget *mW;
};
#endif // DESKTOP_H
