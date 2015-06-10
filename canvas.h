#ifndef CANVAS_H
#define CANVAS_H

#include <QGLWidget>


class Canvas : public QGLWidget
{
public:
    explicit Canvas(QWidget *parent = 0);
    ~Canvas();

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);

    QSize minimumSizeHint() const;
    QSize sizeHint() const;

private:
    void draw();
};

#endif // CANVAS_H
