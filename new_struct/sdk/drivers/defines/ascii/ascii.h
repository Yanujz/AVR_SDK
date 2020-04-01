/*
	

	Author : Yanujz

	Created in : 01/11/2020

    Copyright (C) 2020  Yanujz

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.

	You may contact the author by:
		e-mail: yanujz@live.it
*/
#pragma once

enum CTRL_CODE_C0
{
    CTRL_CODE_C0_NUL = 0x00,    // Null
    CTRL_CODE_C0_SOH = 0x01,    // Start of Heading
    CTRL_CODE_C0_STX = 0x02,    // Start of Text
    CTRL_CODE_C0_ETX = 0x03,    // End of Text
    CTRL_CODE_C0_EOT = 0x04,    // End of Transmission
    CTRL_CODE_C0_ENQ = 0x05,    // Enquiry
    CTRL_CODE_C0_ACK = 0x06,    // Acknowledgement
    CTRL_CODE_C0_BEL = 0x07,    // Bell
    CTRL_CODE_C0_BS  = 0x08,    // Backspace
    CTRL_CODE_C0_HT  = 0x09,    // Horizontal Tab
    CTRL_CODE_C0_LF  = 0x0A,    // Line Feed
    CTRL_CODE_C0_VT  = 0x0B,    // Vertical Tab
    CTRL_CODE_C0_FF  = 0x0C,    // Form Feed
    CTRL_CODE_C0_CR  = 0x0D,    // Carriage Return
    CTRL_CODE_C0_SO  = 0x0E,    // Shift Out
    CTRL_CODE_C0_SI  = 0x0F,    // Shift In
    CTRL_CODE_C0_DLE = 0x10,    // Data Link Escape
    CTRL_CODE_C0_DC1 = 0x11,    // Device Control 1 (often XON)
    CTRL_CODE_C0_DC2 = 0x12,    // Device Control 2
    CTRL_CODE_C0_DC3 = 0x13,    // Device Control 3 (often XOFF)
    CTRL_CODE_C0_DC4 = 0x14,    // Device Control 4
    CTRL_CODE_C0_NAK = 0x15,    // Negative Acknowledgement
    CTRL_CODE_C0_SYN = 0x16,    // Synchronous Idle
    CTRL_CODE_C0_ETB = 0x17,    // End of Transmission Block
    CTRL_CODE_C0_CAN = 0x18,    // Cancel
    CTRL_CODE_C0_EM  = 0x19,    // End of Medium
    CTRL_CODE_C0_SUB = 0x1A,    // Substitute
    CTRL_CODE_C0_ESC = 0x1B,    // Escape
    CTRL_CODE_C0_FS  = 0x1C,    // File Separator
    CTRL_CODE_C0_GS  = 0x1D,    // Group Separator
    CTRL_CODE_C0_RS  = 0x1E,    // Record Separator
    CTRL_CODE_C0_US  = 0x1F,    // Unit Separator

};

enum ASCII {
    ASCII_SPACE = 0x20, // Space
    ASCII_DEL = 0x7F    // Delete
};

enum CTRL_CODE_C1 {
    CTRL_CODE_C1_PAD  = 0x80, // Padding Character
    CTRL_CODE_C1_HOP  = 0x81, // High Octet Preset
    CTRL_CODE_C1_BPH  = 0x82, // Break Permitted Here
    CTRL_CODE_C1_NBH  = 0x83, // No Break Here
    CTRL_CODE_C1_IND  = 0x84, // Index
    CTRL_CODE_C1_NEL  = 0x85, // Next Line
    CTRL_CODE_C1_SSA  = 0x86, // Start of Selected Area
    CTRL_CODE_C1_ESA  = 0x87, // End of Selected Area
    CTRL_CODE_C1_HTS  = 0x88, // Character Tabulation Set - Horizontal Tabulation Set
    CTRL_CODE_C1_HTJ  = 0x89, // Character Tabulation With Justification - Horizontal Tabulation With Justification
    CTRL_CODE_C1_VTS  = 0x8A, // Line Tabulation Set - Vertical Tabulation Set
    CTRL_CODE_C1_PLD  = 0x8B, // Partial Line Forward - Partial Line Down
    CTRL_CODE_C1_PLU  = 0x8C, // Partial Line Backward - Partial Line Up
    CTRL_CODE_C1_RI   = 0x8D, // Reverse Line Feed - Reverse Index
    CTRL_CODE_C1_SS2  = 0x8E, // Single-Shift 2
    CTRL_CODE_C1_SS3  = 0x8F, // Single-Shift 3
    CTRL_CODE_C1_DCS  = 0x90, // Device Control String
    CTRL_CODE_C1_PU1  = 0x91, // Private Use 1
    CTRL_CODE_C1_PU2  = 0x92, // Private Use 2
    CTRL_CODE_C1_STS  = 0x93, // Set Transmit State
    CTRL_CODE_C1_CCH  = 0x94, // Cancel character
    CTRL_CODE_C1_MW   = 0x95, // Message Waiting
    CTRL_CODE_C1_SPA  = 0x96, // Start of Protected Area
    CTRL_CODE_C1_EPA  = 0x97, // End of Protected Area
    CTRL_CODE_C1_SOS  = 0x98, // Start of String
    CTRL_CODE_C1_SGCI = 0x99, // Single Graphic Character Introducer
    CTRL_CODE_C1_SCI  = 0x9A, // Single Character Introducer
    CTRL_CODE_C1_CSI  = 0x9B, // Control Sequence Introducer
    CTRL_CODE_C1_ST   = 0x9C, // String Terminator
    CTRL_CODE_C1_OSC  = 0x9D, // Operating System Command
    CTRL_CODE_C1_PM   = 0x9E, // Privacy Message
    CTRL_CODE_C1_APC  = 0x9F  // Application Program Command
};




