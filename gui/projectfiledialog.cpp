/*
 * Cppcheck - A tool for static C/C++ code analysis
 * Copyright (C) 2007-2010 Daniel Marjam�ki and Cppcheck team.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <QStringList>
#include "projectfiledialog.h"

ProjectFileDialog::ProjectFileDialog(const QString &path, QWidget *parent)
    : QDialog(parent)
{
    mUI.setupUi(this);

    connect(mUI.mButtons, SIGNAL(accepted()), this, SLOT(accept()));
}

QStringList ProjectFileDialog::GetIncludePaths() const
{
    QString include = mUI.mEditIncludePaths->text();
    QStringList includes;
    if (!include.isEmpty())
    {
        include = include.trimmed();
        if (include.indexOf(';') != -1)
            includes = include.split(";");
        else
            includes.append(include);
    }
    return includes;
}

QStringList ProjectFileDialog::GetDefines() const
{
    QString define = mUI.mEditDefines->text();
    QStringList defines;
    if (!define.isEmpty())
    {
        define = define.trimmed();
        if (define.indexOf(';') != -1)
            defines = define.split(";");
        else
            defines.append(define);
    }
    return defines;
}

void ProjectFileDialog::SetIncludepaths(const QStringList &includes)
{
    QString includestr;
    QString dir;
    foreach(dir, includes)
    {
        includestr += dir;
        includestr += ";";
    }
    mUI.mEditIncludePaths->setText(includestr);
}

void ProjectFileDialog::SetDefines(const QStringList &defines)
{
    QString definestr;
    QString define;
    foreach(define, defines)
    {
        definestr += define;
        definestr += ";";
    }
    mUI.mEditDefines->setText(definestr);
}
