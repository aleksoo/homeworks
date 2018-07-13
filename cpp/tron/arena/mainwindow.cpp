#include <QtGui>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QAction>
#include <QToolBar>
#include <QLineEdit>
#include <QPushButton>
#include <QFileDialog>
#include <QMessageBox>
#include <QDesktopWidget>
#include <QStatusBar>
#include <QSlider>
#include "board.h"
#include "mainwindow.h"

const int MOVE_TIMEOUT = 100;
const int PLAYER_TIMEOUT = 10000;

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , m_blueProcess(this)
    , m_redProcess(this)
    , m_board(nullptr)
    , m_blueEdit(nullptr)
    , m_redEdit(nullptr)
    , m_mapEdit(nullptr)
    , m_startButton(nullptr)
    , m_stopButton(nullptr)
    , m_blueButton(nullptr)
    , m_redButton(nullptr)
    , m_mapButton(nullptr)
    , m_isStarted(false)
    , m_blueMoved(false)
    , m_redMoved(false)
    , m_blueMove('\0')
    , m_redMove('\0')
{
    setup();

    connect(&m_blueProcess, SIGNAL(readyReadStandardOutput()), this, SLOT(sltBlueReady()));
    connect(&m_redProcess, SIGNAL(readyReadStandardOutput()), this, SLOT(sltRedReady()));

    m_moveTimer.setSingleShot(true);
    m_blueTimer.setSingleShot(true);
    m_redTimer.setSingleShot(true);
    connect(&m_moveTimer, SIGNAL(timeout()), this, SLOT(sltNextMove()));
    connect(&m_blueTimer, SIGNAL(timeout()), this, SLOT(sltBlueTimeout()));
    connect(&m_redTimer, SIGNAL(timeout()), this, SLOT(sltRedTimeout()));
}

MainWindow::~MainWindow()
{
}

void MainWindow::setup()
{
    QWidget* widget = new QWidget;

    m_board = new Board;

    QVector<QString> map =
    {
        "####################",
        "#                  #",
        "#        22222222  #",
        "#    22222         #",
        "#   111            #",
        "#   1              #",
        "# 111              #",
        "# 1111             #",
        "#                  #",
        "####################",
    };

    //m_board->draw(map);

    QHBoxLayout* blueControls = new QHBoxLayout;
    QHBoxLayout* redControls = new QHBoxLayout;
    QHBoxLayout* mapControls = new QHBoxLayout;

    m_blueEdit = new QLineEdit;
    m_redEdit = new QLineEdit;
    m_mapEdit = new QLineEdit;

    m_blueEdit->setReadOnly(true);
    m_redEdit->setReadOnly(true);
    m_mapEdit->setReadOnly(true);

    m_blueButton = new QPushButton("Niebieski");
    m_redButton = new QPushButton("Czerwony");
    m_mapButton = new QPushButton("Mapa");

    connect(m_blueButton, SIGNAL(clicked(bool)), this, SLOT(sltSelectBlue()));
    connect(m_redButton, SIGNAL(clicked(bool)), this, SLOT(sltSelectRed()));
    connect(m_mapButton, SIGNAL(clicked(bool)), this, SLOT(sltSelectMap()));

    blueControls->addWidget(m_blueButton);
    blueControls->addWidget(m_blueEdit);
    redControls->addWidget(m_redButton);
    redControls->addWidget(m_redEdit);
    mapControls->addWidget(m_mapButton);
    mapControls->addWidget(m_mapEdit);

    QHBoxLayout* bottomControls = new QHBoxLayout;

    m_startButton = new QPushButton("Start");
    m_stopButton = new QPushButton("Stop");
    m_startButton->setDisabled(true);
    m_stopButton->setDisabled(true);

    connect(m_startButton, SIGNAL(clicked(bool)), this, SLOT(sltStart()));
    connect(m_stopButton, SIGNAL(clicked(bool)), this, SLOT(sltStop()));

    bottomControls->addWidget(m_startButton);
    bottomControls->addWidget(m_stopButton);

    m_slider = new QSlider(Qt::Horizontal);
    m_slider->setEnabled(false);
    connect(m_slider, SIGNAL(valueChanged(int)), this, SLOT(sltSliderMoved(int)));

    QVBoxLayout* layout = new QVBoxLayout;

    layout->addLayout(blueControls);
    layout->addLayout(redControls);
    layout->addLayout(mapControls);
    layout->addLayout(bottomControls);
    layout->addWidget(m_board);
    layout->addWidget(m_slider);

    statusBar()->showMessage("Akademia Programowania 2018, Piotr Skotnicki");

    widget->setLayout(layout);
    setCentralWidget(widget);
    setWindowTitle(QCoreApplication::applicationName());
    //setFixedSize(800, 700);
    move(300, 100);
    resize(QDesktopWidget().availableGeometry(this).size() * 0.7);
}

void MainWindow::sltBlueTimeout()
{
    m_blueProcess.terminate();

    sltStop();

    QMessageBox::information(this, "Koniec", "Niebieski przekroczył czas!", QMessageBox::Ok);
}

void MainWindow::sltRedTimeout()
{
    m_redProcess.terminate();

    sltStop();

    QMessageBox::information(this, "Koniec", "Czerwony przekroczył czas!", QMessageBox::Ok);
}

void MainWindow::sltBlueReady()
{
    m_blueTimer.stop();
    m_blueMoved = true;

    char move[2];
    if (m_blueProcess.readLine(move, 2) > 0)
    {
        m_blueMove = move[0];
    }
    else
    {
        sltStop();

        QMessageBox::information(this, "Koniec", "Niebieski nie wykonał ruchu!", QMessageBox::Ok);
    }

    m_blueProcess.close();

    processMoves();
}

void MainWindow::sltRedReady()
{
    m_redTimer.stop();
    m_redMoved = true;

    char move[2];
    if (m_redProcess.readLine(move, 2) > 0)
    {
        m_redMove = move[0];
    }
    else
    {
        sltStop();

        QMessageBox::information(this, "Koniec", "Czerwony nie wykonał ruchu!", QMessageBox::Ok);
    }

    m_redProcess.close();

    processMoves();
}

void MainWindow::sltNextMove()
{
    m_blueMoved = false;
    m_redMoved = false;

    m_blueMove = '\0';
    m_redMove = '\0';

    m_blueProcess.start(m_blueEdit->text());
    m_redProcess.start(m_redEdit->text());

    QString line = QString::number(m_blackMap[0].size()) + " " + QString::number(m_blackMap.size()) + "\n";
    m_blueProcess.write(line.toUtf8());
    m_redProcess.write(line.toUtf8());

    for (int row = 0; row < m_blackMap.size(); ++row)
    {
        for (int col = 0; col < m_blackMap[row].size(); ++col)
        {
            char c = m_blackMap[row][col].toLatin1();

            m_blueProcess.write(QString(c).toUtf8());

            if (c == '1') c = '2';
            else if (c == '2') c = '1';

            m_redProcess.write(QString(c).toUtf8());
        }
        m_blueProcess.write("\n");
        m_redProcess.write("\n");
    }

    m_blueProcess.closeWriteChannel();
    m_redProcess.closeWriteChannel();

    m_blueTimer.start(PLAYER_TIMEOUT);
    m_redTimer.start(PLAYER_TIMEOUT);
}

void MainWindow::sltSelectBlue()
{
    QString file = QFileDialog::getOpenFileName(this, tr("Wybierz niebieski"));

    m_blueEdit->setText(file);

    updateButtons();
}

void MainWindow::sltSelectRed()
{
    QString file = QFileDialog::getOpenFileName(this, tr("Wybierz czerwony"));

    m_redEdit->setText(file);

    updateButtons();
}

void MainWindow::sltSelectMap()
{
    QString file = QFileDialog::getOpenFileName(this, tr("Wybierz mapę"));

    m_mapEdit->setText(file);

    updateButtons();
}

void MainWindow::sltStart()
{
    m_movesList.clear();

    m_startButton->setEnabled(false);
    m_stopButton->setEnabled(true);

    m_blueButton->setEnabled(false);
    m_redButton->setEnabled(false);
    m_mapButton->setEnabled(false);

    m_slider->setMaximum(0);
    m_slider->setValue(0);
    m_slider->setEnabled(false);

    QFile mapFile(m_mapEdit->text());
    if (!mapFile.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(this, "Błąd", "Plik z mapą jest nieprawidłowy", QMessageBox::Ok);
        sltStop();
        return;
    }

    QTextStream in(&mapFile);

    m_map.clear();
    m_blackMap.clear();

    if (!in.atEnd())
    {
        in.readLine();
    }

    while (!in.atEnd())
    {
        QString line = in.readLine();
        m_map.append(line);
        m_blackMap.append(line);
    }

    m_board->draw(m_map);
    m_movesList.push_back(m_map);

    m_isStarted = true;

    m_moveTimer.start(MOVE_TIMEOUT);
}

void MainWindow::sltStop()
{
    m_isStarted = false;

    m_moveTimer.stop();

    if (m_blueTimer.isActive())
    {
        m_blueProcess.terminate();
        m_blueTimer.stop();
    }

    if (m_redTimer.isActive())
    {
        m_redProcess.terminate();
        m_redTimer.stop();
    }

    m_startButton->setEnabled(true);
    m_stopButton->setEnabled(false);

    m_blueButton->setEnabled(true);
    m_redButton->setEnabled(true);
    m_mapButton->setEnabled(true);

    m_slider->setMaximum(m_movesList.size() - 1);
    m_slider->setValue(m_movesList.size() - 1);
    m_slider->setEnabled(true);
}

void MainWindow::updateButtons()
{
    m_startButton->setEnabled(m_blueEdit->text().size() > 0 && m_redEdit->text().size() > 0 && m_mapEdit->text().size() > 0);
}

void MainWindow::processMoves()
{
    if (m_blueMoved && m_redMoved)
    {
        bool invalidRedMove = false;
        bool invalidBlueMove = false;

        bool blueDone = false;
        bool redDone = false;

        int blueNextRow = 0;
        int blueNextCol = 0;

        int redNextRow = 0;
        int redNextCol = 0;

        for (int row = 0; row < m_blackMap.size(); ++row)
        {
            for (int col = 0; col < m_blackMap[row].size(); ++col)
            {
                if (!blueDone && m_blackMap[row][col] == '1')
                {
                    blueDone = true;

                    int nextRow = row;
                    int nextCol = col;

                    if (m_blueMove == '1') nextRow -= 1;
                    else if (m_blueMove == '3') nextRow += 1;
                    else if (m_blueMove == '2') nextCol += 1;
                    else if (m_blueMove == '4') nextCol -= 1;
                    else invalidBlueMove = true;

                    if (!invalidBlueMove)
                    {
                        if (m_map[nextRow][nextCol] != '3')
                        {
                            m_map[nextRow][nextCol] = '1';
                        }

                        if (m_blackMap[nextRow][nextCol] != ' ')
                        {
                            if (redDone && nextRow == redNextRow && nextCol == redNextCol)
                            {
                                invalidRedMove = true;

                                m_map[nextRow][nextCol] = '3';
                            }
                            invalidBlueMove = true;
                        }
                        else
                        {
                            m_blackMap[row][col] = '#';
                            m_blackMap[nextRow][nextCol] = '1';
                            blueNextRow = nextRow;
                            blueNextCol = nextCol;
                        }
                    }
                }

                if (!redDone && m_blackMap[row][col] == '2')
                {
                    redDone = true;

                    int nextRow = row;
                    int nextCol = col;

                    if (m_redMove == '1') nextRow -= 1;
                    else if (m_redMove == '3') nextRow += 1;
                    else if (m_redMove == '2') nextCol += 1;
                    else if (m_redMove == '4') nextCol -= 1;
                    else invalidRedMove = true;

                    if (!invalidRedMove)
                    {
                        if (m_map[nextRow][nextCol] != '3')
                        {
                            m_map[nextRow][nextCol] = '2';
                        }

                        if (m_blackMap[nextRow][nextCol] != ' ')
                        {
                            if (blueDone && nextRow == blueNextRow && nextCol == blueNextCol)
                            {
                                invalidBlueMove = true;

                                m_map[nextRow][nextCol] = '3';
                            }
                            invalidRedMove = true;
                        }
                        else
                        {
                            m_blackMap[row][col] = '#';
                            m_blackMap[nextRow][nextCol] = '2';
                            redNextRow = nextRow;
                            redNextCol = nextCol;
                        }
                    }
                }
            }
        }

        m_board->draw(m_map);
        m_movesList.push_back(m_map);

        if (invalidRedMove || invalidBlueMove)
        {
            if (invalidRedMove && invalidBlueMove)
            {
                QMessageBox::information(this, "Koniec", "Obaj gracze przegrali!", QMessageBox::Ok);
            }
            else if (invalidRedMove)
            {
                QMessageBox::information(this, "Koniec", "Niebieski wygrał!", QMessageBox::Ok);
            }
            else if (invalidBlueMove)
            {
                QMessageBox::information(this, "Koniec", "Czerwony wygrał!", QMessageBox::Ok);
            }

            sltStop();
        }
        else
        {
            if (m_isStarted)
            {
                m_moveTimer.start(MOVE_TIMEOUT);
            }
        }
    }
}

void MainWindow::sltSliderMoved(int move)
{
    if (m_movesList.size() > 0 && move < m_movesList.size())
    {
        m_board->draw(m_movesList[move]);
    }
}
