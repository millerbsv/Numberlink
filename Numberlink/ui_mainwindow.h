/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbrir;
    QAction *actionSalir;
    QAction *action_C_mo_funciona;
    QAction *actionCreadores;
    QAction *actionIngenuo;
    QAction *actionBacktracking;
    QAction *actionVoraz;
    QAction *actionVerificar;
    QAction *actionColorear;
    QWidget *centralWidget;
    QTextEdit *textEdit;
    QMenuBar *menuBar;
    QMenu *menuArchivo;
    QMenu *menuAyuda;
    QMenu *menuSoluci_n;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(592, 386);
        MainWindow->setLayoutDirection(Qt::LeftToRight);
        actionAbrir = new QAction(MainWindow);
        actionAbrir->setObjectName(QStringLiteral("actionAbrir"));
        actionSalir = new QAction(MainWindow);
        actionSalir->setObjectName(QStringLiteral("actionSalir"));
        action_C_mo_funciona = new QAction(MainWindow);
        action_C_mo_funciona->setObjectName(QStringLiteral("action_C_mo_funciona"));
        actionCreadores = new QAction(MainWindow);
        actionCreadores->setObjectName(QStringLiteral("actionCreadores"));
        actionIngenuo = new QAction(MainWindow);
        actionIngenuo->setObjectName(QStringLiteral("actionIngenuo"));
        actionBacktracking = new QAction(MainWindow);
        actionBacktracking->setObjectName(QStringLiteral("actionBacktracking"));
        actionVoraz = new QAction(MainWindow);
        actionVoraz->setObjectName(QStringLiteral("actionVoraz"));
        actionVerificar = new QAction(MainWindow);
        actionVerificar->setObjectName(QStringLiteral("actionVerificar"));
        actionColorear = new QAction(MainWindow);
        actionColorear->setObjectName(QStringLiteral("actionColorear"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(370, 10, 211, 311));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 592, 21));
        menuArchivo = new QMenu(menuBar);
        menuArchivo->setObjectName(QStringLiteral("menuArchivo"));
        menuAyuda = new QMenu(menuBar);
        menuAyuda->setObjectName(QStringLiteral("menuAyuda"));
        menuSoluci_n = new QMenu(menuBar);
        menuSoluci_n->setObjectName(QStringLiteral("menuSoluci_n"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuArchivo->menuAction());
        menuBar->addAction(menuSoluci_n->menuAction());
        menuBar->addAction(menuAyuda->menuAction());
        menuArchivo->addSeparator();
        menuArchivo->addAction(actionAbrir);
        menuArchivo->addSeparator();
        menuArchivo->addAction(actionSalir);
        menuAyuda->addSeparator();
        menuAyuda->addAction(action_C_mo_funciona);
        menuAyuda->addAction(actionCreadores);
        menuSoluci_n->addAction(actionIngenuo);
        menuSoluci_n->addAction(actionBacktracking);
        menuSoluci_n->addSeparator();
        menuSoluci_n->addAction(actionVoraz);
        menuSoluci_n->addAction(actionVerificar);
        menuSoluci_n->addAction(actionColorear);
        mainToolBar->addAction(actionAbrir);
        mainToolBar->addAction(actionVerificar);
        mainToolBar->addAction(actionIngenuo);
        mainToolBar->addAction(actionBacktracking);
        mainToolBar->addAction(actionVoraz);
        mainToolBar->addAction(actionColorear);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "NumberLink", 0));
        actionAbrir->setText(QApplication::translate("MainWindow", "Abrir", 0));
        actionSalir->setText(QApplication::translate("MainWindow", "Salir", 0));
        action_C_mo_funciona->setText(QApplication::translate("MainWindow", "\302\277C\303\263mo funciona?", 0));
        actionCreadores->setText(QApplication::translate("MainWindow", "Creadores", 0));
        actionIngenuo->setText(QApplication::translate("MainWindow", "Ingenuo", 0));
        actionBacktracking->setText(QApplication::translate("MainWindow", "Backtracking", 0));
        actionVoraz->setText(QApplication::translate("MainWindow", "Voraz", 0));
        actionVerificar->setText(QApplication::translate("MainWindow", "Verificar", 0));
        actionColorear->setText(QApplication::translate("MainWindow", "Colorear", 0));
        menuArchivo->setTitle(QApplication::translate("MainWindow", "Archivo", 0));
        menuAyuda->setTitle(QApplication::translate("MainWindow", "Ayuda", 0));
        menuSoluci_n->setTitle(QApplication::translate("MainWindow", "Soluci\303\263n", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
