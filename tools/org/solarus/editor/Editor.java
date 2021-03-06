/*
 * Copyright (C) 2006-2012 Christopho, Solarus - http://www.solarus-games.org
 *
 * Solarus Quest Editor is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Zelda: Mystery of Solarus DX is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */
package org.solarus.editor;

import org.solarus.editor.gui.*;

/**
 * Main class of the quest editor.
 */
public class Editor {

    /**
     * Entry point.
     * Usage: java org.solarus.editor.Editor [quest_path]  
     */
    public static void main(String[] args) {

        String questPath = (args.length != 0) ? args[0] : null;

        // create the main window
        EditorWindow window = new EditorWindow(questPath);
        window.pack();
        window.setExtendedState(EditorWindow.MAXIMIZED_BOTH);
        window.setVisible(true);
    }
}

