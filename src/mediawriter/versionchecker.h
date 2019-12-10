/*
 * Fedora Media Writer
 * Copyright (C) 2017 Martin Bříza <mbriza@redhat.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef VERSIONCHECKER_H
#define VERSIONCHECKER_H

#include <QObject>

#include "downloadmanager.h"
#include "utilities.h"

class VersionChecker;

class VersionChecker : public QObject, protected DownloadReceiver {
    Q_OBJECT
    Q_PROPERTY(QString newerVersion READ newerVersion NOTIFY newerVersionChanged)
    Q_PROPERTY(QUrl url READ url NOTIFY newerVersionChanged)
public:
    VersionChecker(QObject *parent = nullptr);
    void onStringDownloaded(const QString &text) override;
    void onDownloadError(const QString &message) override;

    QString newerVersion() const;
    QUrl url() const;
protected:
    bool isVersionHigher(QString currentVersion, QString newVersion);
signals:
    void newerVersionChanged();
private:
    QString m_newerVersion { };
    QUrl m_url { };
};

#endif // VERSIONCHECKER_H
