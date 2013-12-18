/* This file is part of the KDE project
   Copyright (C) 2003 Ignacio Castaño <castano@ludicon.com>

   This program is free software; you can redistribute it and/or
   modify it under the terms of the Lesser GNU General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.
*/

#ifndef KIMG_DDS_H
#define KIMG_DDS_H

#include <QImageIOPlugin>

class DDSHandler : public QImageIOHandler
{
public:
    DDSHandler();

    virtual bool canRead() const;
    virtual bool read(QImage *image);

    static bool canRead(QIODevice *device);
};

class DDSPlugin : public QImageIOPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QImageIOHandlerFactoryInterface" FILE "dds.json")

public:
    virtual Capabilities capabilities(QIODevice *device, const QByteArray &format) const;
    virtual QImageIOHandler *create(QIODevice *device, const QByteArray &format = QByteArray()) const;
};

#endif // KIMG_DDS_H

