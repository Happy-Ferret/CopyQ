/*
    Copyright (c) 2018, Lukas Holecek <hluk@email.cz>

    This file is part of CopyQ.

    CopyQ is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    CopyQ is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with CopyQ.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef PROCESSMANAGERDIALOG_H
#define PROCESSMANAGERDIALOG_H

#include <QDialog>

class Action;

namespace Ui {
class ProcessManagerDialog;
}

class ProcessManagerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ProcessManagerDialog(QWidget *parent = nullptr);

    ~ProcessManagerDialog();

    void actionAboutToStart(Action *action);
    void actionStarted(Action *action);
    void actionFinished(Action *action);
    void actionFinished(const QString &name);

protected:
    void showEvent(QShowEvent *event) override;

private slots:
    void onRemoveActionButtonClicked();
    void onDeleteShortcut();

private:
    class TableRow;
    TableRow tableRowForAction(Action *action) const;
    TableRow tableRowForActionButton(QObject *button) const;
    bool removeIfNotRunning(int row);
    void updateTable();
    TableRow createTableRow(const QString &name, Action *action = nullptr);
    QWidget *createRemoveButton(Action *action = nullptr);

    Ui::ProcessManagerDialog *ui;
};

#endif // PROCESSMANAGERDIALOG_H
