/*
 * Fedora Media Writer
 * Copyright (C) 2016 Martin Bříza <mbriza@redhat.com>
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

import QtQuick 2.0

Item {
    id: root
    width: $(64)
    height: $(64)

    property real shorterSide: Math.floor(width < height ? width : height)
    property color color: "red"

    Item {
        width: parent.shorterSide
        height: parent.shorterSide
        anchors.centerIn: parent
        rotation: 45
        transformOrigin: Item.Center
        Rectangle {
            anchors.centerIn: parent
            width: parent.width * 1.15
            height: parent.width * 0.25
            color: root.color
        }
        Rectangle {
            anchors.centerIn: parent
            width: parent.width * 0.25
            height: parent.width * 1.15
            color: root.color
        }
    }
}
