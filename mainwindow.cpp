#include "mainwindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QLayout>
#include <QSpinBox>
#include <QTableWidget>
#include <QHeaderView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    centralWidget = new QWidget(this);
    this->setCentralWidget(centralWidget);

    QHBoxLayout *mainLayout = new QHBoxLayout;

    QTableWidget* table = new QTableWidget(this);
    mainLayout->addWidget(table);
    table->setColumnCount(2);
    //table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    table->resize(20, table->height());
    table->setBaseSize(20,20);
    canvas = new Canvas(this);

    // Main MenuBar
    menuBar = new QMenuBar(canvas);

    // File Menus
    QMenu* fileMenu = new QMenu("File");

    QPixmap openPix("img/folder_picture.png");
    QAction* open = new QAction(openPix, "&Open", this);
    fileMenu->addAction(open);

    fileMenu->addSeparator();

    QPixmap savePix("img/disk.png");
    QAction* save = new QAction(savePix, "&Save", this);
    fileMenu->addAction(save);

    QPixmap saveAsPix("img/disk_multiple.png");
    QAction* saveAs = new QAction(saveAsPix, "&Save As", this);
    fileMenu->addAction(saveAs);

    fileMenu->addSeparator();

    QPixmap quitPix("img/door_out.png");
    QAction* quit = new QAction(quitPix, "&Quit", this);
    fileMenu->addAction(quit);

    // Edit Menu
    QMenu* editMenu = new QMenu("Edit");

    QPixmap cutPix("img/cut.png");
    QAction* cut = new QAction(cutPix, "&Cut", this);
    editMenu->addAction(cut);

    QPixmap copyPix("img/copy.png");
    QAction* copy = new QAction(copyPix, "&Copy", this);
    editMenu->addAction(copy);

    QPixmap pastePix("img/paste.png");
    QAction* paste = new QAction(pastePix, "&Paste", this);
    editMenu->addAction(paste);

    editMenu->addSeparator();

    editMenu->addAction("Sprite");
    editMenu->addAction("Animation");

    // View Menus
    QMenu* viewMenu = new QMenu("View");

    QPixmap gridPix("img/grid.png");
    QAction* viewGrid = new QAction(gridPix, "&Grid", this);
    viewMenu->addAction(viewGrid);
    viewGrid->setCheckable(true);
    viewGrid->setChecked(true);

    QAction *viewSprite = viewMenu->addAction("Sprite");
    viewSprite->setCheckable(true);
    viewSprite->setChecked(true);

    QAction *viewSymmetry = viewMenu->addAction("Symmetry Hints");
    viewSymmetry->setCheckable(true);
    viewSymmetry->setChecked(true);

    viewMenu->addSeparator();

    QPixmap zoomInPix("img/zoom_in.png");
    QAction* zoomIn = new QAction(zoomInPix, "&Zoom In", this);
    viewMenu->addAction(zoomIn);

    QPixmap zoomOutPix("img/zoom_out.png");
    QAction* zoomOut = new QAction(zoomOutPix, "&Zoom Out", this);
    viewMenu->addAction(zoomOut);

    QPixmap zoom100Pix("img/zoom.png");
    QAction* zoom100 = new QAction(zoom100Pix, "&Actual Size", this);
    viewMenu->addAction(zoom100);

    // Help Menus
    QMenu* helpMenu = new QMenu("Help");
    QPixmap aboutPix("img/star.png");
    QAction* about = new QAction(aboutPix, "&About", this);
    helpMenu->addAction(about);

    menuBar->addMenu(fileMenu);
    menuBar->addMenu(editMenu);
    menuBar->addMenu(viewMenu);
    menuBar->addMenu(helpMenu);

    // ToolBar
    QToolBar* toolBar = new QToolBar(canvas);

    toolBar->addAction(open);

    toolBar->addSeparator();

    toolBar->addAction(save);
    toolBar->addAction(saveAs);

    toolBar->addSeparator();

    toolBar->addAction(cut);
    toolBar->addAction(copy);
    toolBar->addAction(paste);

    toolBar->addSeparator();

    toolBar->addAction(viewGrid);

    toolBar->addSeparator();

    QSpinBox* gridX = new QSpinBox(this);
    gridX->setPrefix("X: ");
    toolBar->addWidget(gridX);

    toolBar->addSeparator();

    QSpinBox* gridY = new QSpinBox(this);
    gridY->setPrefix("Y: ");
    toolBar->addWidget(gridY);

    toolBar->addSeparator();

    toolBar->addAction(zoomIn);
    toolBar->addAction(zoomOut);
    toolBar->addAction(zoom100);

    toolBar->addSeparator();

    QDoubleSpinBox* speed = new QDoubleSpinBox(this);
    speed->setPrefix("Speed: ");
    speed->setDecimals(3);
    speed->setSingleStep(0.001);
    speed->setAccelerated(true);
    toolBar->addWidget(speed);

    mainLayout->addWidget(canvas);
    setMenuBar(menuBar);
    addToolBar(toolBar);

    toolBar->addSeparator();

    QPixmap playPix("img/play.png");
    QAction* play = new QAction(playPix, "&Play", this);
    toolBar->addAction(play);

    QPixmap pausePix("img/pause.png");
    QAction* pause = new QAction(pausePix, "&Pause", this);
    toolBar->addAction(pause);

    QPixmap stopPix("img/stop.png");
    QAction* stop = new QAction(stopPix, "&Stop", this);
    toolBar->addAction(stop);

    toolBar->addSeparator();

    QSpinBox* frame = new QSpinBox(this);
    frame->setPrefix("Frame: ");
    toolBar->addWidget(frame);

    mainLayout->setMargin(0);
    centralWidget->setLayout(mainLayout);
}

MainWindow::~MainWindow()
{
    delete canvas;
}
