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
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNuevo;
    QAction *actionAbrir;
    QAction *actionSalir;
    QAction *action_C_mo_funciona;
    QAction *actionCreadores;
    QAction *actionIngenuo;
    QAction *actionBacktracking;
    QAction *actionVoraz;
    QAction *actionNuestra_soluci_n;
    QAction *actionVerificar;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuArchivo;
    QMenu *menuAyuda;
    QMenu *menuColor;
    QMenu *menuSoluci_n;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(344, 300);
        actionNuevo = new QAction(MainWindow);
        actionNuevo->setObjectName(QStringLiteral("actionNuevo"));
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
        actionNuestra_soluci_n = new QAction(MainWindow);
        actionNuestra_soluci_n->setObjectName(QStringLiteral("actionNuestra_soluci_n"));
        actionVerificar = new QAction(MainWindow);
        actionVerificar->setObjectName(QStringLiteral("actionVerificar"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 344, 21));
        menuArchivo = new QMenu(menuBar);
        menuArchivo->setObjectName(QStringLiteral("menuArchivo"));
        menuAyuda = new QMenu(menuBar);
        menuAyuda->setObjectName(QStringLiteral("menuAyuda"));
        menuColor = new QMenu(menuBar);
        menuColor->setObjectName(QStringLiteral("menuColor"));
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
        menuBar->addAction(menuColor->menuAction());
        menuBar->addAction(menuAyuda->menuAction());
        menuArchivo->addAction(actionNuevo);
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
        menuSoluci_n->addAction(actionNuestra_soluci_n);
        menuSoluci_n->addAction(actionVerificar);
        mainToolBar->addAction(actionNuevo);
        mainToolBar->addAction(actionAbrir);
        mainToolBar->addAction(action_C_mo_funciona);
        mainToolBar->addAction(actionVerificar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "NumberLink", 0));
        actionNuevo->setText(QApplication::translate("MainWindow", "Nuevo", 0));
        actionAbrir->setText(QApplication::translate("MainWindow", "Abrir", 0));
        actionSalir->setText(QApplication::translate("MainWindow", "Salir", 0));
        action_C_mo_funciona->setText(QApplication::translate("MainWindow", "\302\277C\303\263mo funciona?", 0));
        actionCreadores->setText(QApplication::translate("MainWindow", "Creadores", 0));
        actionIngenuo->setText(QApplication::translate("MainWindow", "Ingenuo", 0));
        actionBacktracking->setText(QApplication::translate("MainWindow", "Backtracking", 0));
        actionVoraz->setText(QApplication::translate("MainWindow", "Voraz", 0));
        actionNuestra_soluci_n->setText(QApplication::translate("MainWindow", "Nuestra soluci\303\263n", 0));
        actionVerificar->setText(QApplication::translate("MainWindow", "Verificar", 0));
        menuArchivo->setTitle(QApplication::translate("MainWindow", "Archivo", 0));
        menuAyuda->setTitle(QApplication::translate("MainWindow", "Ayuda", 0));
        menuColor->setTitle(QApplication::translate("MainWindow", "Color", 0));
        menuSoluci_n->setTitle(QApplication::translate("MainWindow", "Soluci\303\263n", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
