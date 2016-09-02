
          SecureCRT(R) 6.2.3 (Official) -- September 10, 2009

            Copyright (C) 1995-2009 VanDyke Software, Inc.
                        All rights reserved.


Product Overview
----------------

SecureCRT protects your passwords, user accounts, and data, combining
rock-solid terminal emulation with the strong encryption, broad
authentication options, and data integrity of the Secure Shell (SSH)
protocol.

SecureCRT provides versatile solutions for a wide range of business,
network management, information security, and development tasks, from
accessing host-based applications and administering servers to
securely accessing behind-the-firewall network resources like e-mail,
files, and printers.

SecureCRT supports SSH1, SSH2, Telnet, Telnet/SSL, RLogin, Serial,
and TAPI protocols and authentication via password, public key, X.509
certificate, and Kerberos v5 via GSSAPI.  Ciphers include AES,
Twofish, Blowfish, 3DES, and RC4.

Choose from a wide range of emulations including VT100, VT102, VT220,
ANSI, SCO ANSI, Wyse 50/60, Xterm, and Linux console -– all with ANSI
color.  Multibyte character sets are supported for Japanese, Korean,
and Chinese, as is support for scalable line-drawing fonts.

SecureCRT features a multi-session tabbed interface with extensive
session management and customization features.  Customization options
include toolbars, menus, keymaps, and login scripts, as well as fonts,
cursors, and color schemes. 

Named sessions and firewalls let you create individual configurations
that can be used on a session-specific basis.  Other features include
the Activator tray utility to minimize desktop clutter, auto logon,
printing, Emacs mode, and SOCKS firewall support.

Powerful scripting capabilities, including ActiveX scripting support
for VBScript and other scripting languages, save you valuable time by
automating routine configuration tasks.  Secure file transfers can be
performed using Zmodem or Xmodem from an SSH1 or SSH2 session. 

SecureCRT and the SecureFX(R) file transfer client can be integrated,
letting you share global and session options and the host key database
so configuring a server connection only needs to be done once.

SecureCRT includes a 30-day try-before-you-buy evaluation license for
the fully functional application and access to VanDyke Software(R)
technical support.


Contents
--------

   1. New for SecureCRT 6.2
   2. Enhancement Requests, Updates, and Questions
   3. Encryption Export
   4. Upgrades
   5. Product History
   6. SecureCRT Features
   7. Reporting Bugs
   8. Contact Information


1. New For SecureCRT 6.2
------------------------

The major new features for SecureCRT 6.2 are:

  - New session management options

    - Edit multiple sessions at the same time: The Connect
      dialog allows multiple sessions to be selected and then
      edited, making it easy to do things like change the
      passwords for a group of sessions.

    - Remember and connect to sessions from last use: A new option
      remembers which sessions were open the last time SecureCRT
      ran and connects them automatically.

  - Logging enhancements

    - Rotate SecureCRT log files nightly: There is an option
      to create a new log file at midnight -- you set a variable
      in the log file name to write log output to a new file daily.
      
    - Use parameter substitutions in log file paths: If a log
      file path does not already exist, it will be created
      automatically.

    - Specify different log files for the same session: A
      new command-line parameter /LOG allows a log file to
      be specified on the command line.

  - Improved memory usage
 
    - Increase your scrollback without increasing memory use:
      The scrollback buffer memory is now allocated dynamically
      significantly reducing the amount of memory SecureCRT uses.

  - SSH2-related enhancements

    - Use a smart card to authenticate: Support for PKCS#11
      simplifies smart-card authentication.

    - Manage your keys: Agent support in the Activator allows
      keys to be explicitly added and removed.

  - New installer option

    - 64-bit Windows support: A native 64-bit version is available
      for x64 Windows platforms.

Please see History.txt in the SecureCRT program group for additional 
information on minor changes and bug fixes.


2. Enhancement Requests, Updates, and Questions
-----------------------------------------------

We want to hear from you.  Let us know what features you would like to
see in future releases of SecureCRT by visiting our website at:

  http://www.vandyke.com/feedback.php

Every VanDyke Software license includes a full year of upgrades and
technical support.  To receive e-mail notification when new releases
of SecureCRT are available, sign up for our SecureCRT mailing list at:

  https://secure.vandyke.com/cgi-bin/subscribe.php?RMF=3

For tips, ideas, and product news, subscribe to VanDyke Software's
monthly newsletter at:

  https://secure.vandyke.com/cgi-bin/subscribe.php?RMF=3

You can also exchange useful tips and ideas with your peers and
VanDyke developers by joining the online forums:

  http://forums.vandyke.com/index.php?RMF=3

If you have any questions, please visit our website at:

  http://www.vandyke.com/feedback.php

SecureCRT supports Windows Vista, 2003, and XP for x86 and x64, and
Windows 2000.


3. Encryption Export
--------------------

This Software is subject to export control.  The Software may be
transmitted, exported, or re-exported only under applicable export
laws and restrictions and regulations of the United States Bureau of
Industry and Security or foreign agencies or authorities.  By
downloading or using the Software, you are agreeing to comply with
export controls.  For more information see:

  http://www.vandyke.com/download/export.html


4. Upgrades
-----------

Users who purchased SecureCRT on or after January 1, 2008 are
eligible for a free upgrade to SecureCRT 6.2.  All users can evaluate
SecureCRT 6.2 for 30 days free of charge.  For more information on
upgrade eligibility and purchasing upgrades, please visit:

  http://www.vandyke.com/pricing/corporate/upgrades


5. Product History
------------------

The list of changes made for this release of SecureCRT can be found
in the SecureCRT_History.txt file installed with the program.


6. SecureCRT Features 
---------------------

Support for SSH1 and SSH2 Secure Shell protocols.
  - SSH2 Protocol support:
    - AES-128, AES-192, AES-256, Twofish, Blowfish, 3DES, and RC4
      ciphers.
    - RSA and DSA host key support.
    - Multiple ordered authentication methods, ciphers and MACs.
    - Public Key Assistant makes it easier to upload public keys.
    - Local port forwarding, X11 forwarding, remote forwarding, and
      dynamic forwarding.
    - MD5, MD5-96, SHA1, and SHA1-96 MACs.
    - RSA, DSA, public-key, X.509 certificate, Kerberos v5 via GSSAPI,
      and password authentication methods.
    - SFTP tab creates an SFTP session to an existing SSH session.
  - SSH1 Protocol support:
    - Blowfish, DES, 3DES, and RC4 ciphers.
    - RSA, TIS, and password authentication.
    - Local port forwarding, X11 forwarding.

Session Management.
  - Named sessions store different preferences for different hosts.
  - Tabbed sessions allow multiple sessions in the same window.
  - Tabbed sessions can be moved in and out of windows.
  - Launch multiple selected sessions in tabs with a single click.
  - Option to minimize SecureCRT windows to the Activator utility in
    the system tray.
  - The Activator utility acts as an SSH agent.
  - A session can be logged to a file, including options for logging
    custom data.

Configuration & Customization.
  - Easy configuration of basic SSH, port forwarding, remote
    forwarding and other settings in Session Options dialog.
  - Named firewalls.
  - Customizable toolbar and menus.
  - User-defined number of savelines (scrollback) up to 32,000.
  - User-configurable number of rows and columns.
  - User-defined foreground, background, and bold colors.
  - User-defined keymaps.
  - User-defined button bar.
  - User-defined word delimiter characters for double-click.
  - Emacs mode maps ALT+<key> to send ESC+<key>.

Advanced Terminal Emulation.
  - Quality VT100, VT102, VT220, Linux console, SCO ANSI, Wyse 50/60
    and ANSI emulation:
    - VT line drawing.
    - Support for bold, underline, and reverse attributes.
    - Double-width and double-height fonts.
    - 80/132 column switching.
    - VT100 and VT220 keyboard emulation.
    - Optional ANSI color.
    - 256-color Xterm.
    - Xterm extensions for mouse support and changing title bar.
    - Multi-byte character set support for Japanese, Korean, and
      Chinese.
 
Other Features.
  - FIPS 140-2 validated cryptographic library support.
  - Variable compression increases performance on slow connections.
  - Simple interface for automating logins.
  - Support for Telnet, Telnet/SSL, and RLogin protocols:
    - Telnet supports Negotiate About Window Size (NAWS).
    - Telnet supports Local Flow Control (LFLOW).
  - Serial (COM) device support.
  - Integration with SecureFX 3.x or higher.
  - Scripting language support for VBScript and JScript.
  - Script recorder.
  - Zmodem and Xmodem file transfer (upload and download).
  - Printing: auto print, selection, screen, and pass-through 
    printing.
  - Modem dialer support: configure and save modem, country code,
    phone, and redial settings for TAPI sessions.
  - SOCKS firewall support with password authentication.
  - Unauthenticated and basic HTTP proxy support.
  - Generic proxy firewall support.
  - Copy and paste, including an "auto copy" option and a "paste on
    middle or right mouse click" option.
  - Chat window option provides an editable type-ahead buffer with
    history support.
  - Support for use from the command line or web browsers.
  - Support for standard insertion caret so that it can be tracked
    by screen access technology for the blind.


7. Reporting Bugs
-----------------

If you experience something you believe is a bug, please fill out
our online form at:

  http://www.vandyke.com/feedback.php

Please do not assume someone else will report it.  We will try to
resolve reported bugs as quickly as possible.  However, we can't
resolve bugs that are not reported.

Please describe the problem in as much detail as possible. Please
include the following information:

  - Version of SecureCRT (as shown in the About dialog)
  - Operating system and version


8. Contact Information
-----------------------

For information on ordering licenses, please visit the VanDyke
Software website:

  http://www.vandyke.com


All other inquiries should be directed to:

  VanDyke Software, Inc.
  4848 Tramway Ridge Dr. NE
  Suite 101
  Albuquerque, NM 87111
  USA

  Inquiry form: http://www.vandyke.com/feedback.php


VanDyke Software, SecureCRT, and SecureFX are trademarks or registered trademarks of VanDyke Software, Inc. in the United States and/or other
countries.

All other products and services mentioned are trademarks or registered
trademarks of their respective companies.