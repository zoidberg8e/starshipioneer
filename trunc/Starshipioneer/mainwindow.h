#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGLWidget>
#include <QTimer>

class MainWindow : public QGLWidget
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

private:
    QTimer timer;

    GLuint backTex;
};

#endif // MAINWINDOW_H
