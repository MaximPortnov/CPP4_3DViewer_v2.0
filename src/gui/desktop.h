#ifndef DESKTOP_H
#define DESKTOP_H

#include <QMainWindow>
#include <QFileDialog>
#include <QPixmap>
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

    void on_spinBox_valueChanged(int arg1);

    void on_spinBox_2_valueChanged(int arg1);

    void on_spinBox_4_valueChanged(int arg1);

    void on_spinBox_5_valueChanged(int arg1);

    void on_spinBox_6_valueChanged(int arg1);

    void on_spinBox_7_valueChanged(int arg1);

    void on_spinBox_9_valueChanged(int arg1);
    

    void on_spinBox_3_valueChanged(int arg1);

    void on_spinBox_8_valueChanged(int arg1);

    void on_spinBox_12_valueChanged(int arg1);
    void on_pushButton_6_clicked();
    

private:
  bool animate = false;
    Ui::MainWindow *ui;
    MyWidget *mW;
};
#endif // DESKTOP_H
