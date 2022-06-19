# Peripherials
There are multiple classes of devices that (potentially) could be connected to your phone.

## Bluetooth
If your device has Bluetooth support, you should be able to connect a Bluetooth keyboard or send files over the BLE protocol.

## USB
Many devices have USB support. The newest models usually offer full USB Host functionality, with the range of supported devices limited only by built-in drivers in the phone. Phones with USB-C usually allow connecting external displays, keyboards and storage devices.

## SDIO
There are far more devices supporting SDIO than devices with USB Host capabilities. The implementation of SDIO might not be complete. Still, at the very least, with some hacking and a handful of digital electronics, you should be able to use an SDIO slot as an SPI port.

## Earphones/microphone jack
Suppose all the other options have failed you, yet, your device can still run third-party applications with microphone access. In that case, you might be able to communicate with your device over the earphone/microphone jack. But we cannot recommend this option.


# Android phones and tablets
If your device isn't vendor-locked, you should be able to install third-party applications, unlocking the computing potential of your devices. If your device is vendor-locked, you can try to use the manual for JS-enabled devices. Usually, you should be able to sideload the applications if you wish (load them from local storage rather than AppStore).

## Built-in tools
Unfortunately, most Android devices do not have tools that would allow performing PC-like tasks by default.

## Terminal emulator
There are many "Terminal Emulators" available for Android. Even in its most basic form, the terminal emulator will provide you access to scripting in the shell and essential OS functions.

## Programming languages
There are numerous interpreters and compilers installable for Android. Most of them run in Android UI, but some are useable from the Terminal Emulator. Check out SL4A, for example.

## Emulators
There are plenty of emulators of other platforms to choose from, but only if you have them downloaded or have access to the internet, of course.


# iOS phones and tablets
Devices using iOS must have access to the internet to install the applications (unless they have been rooted). Suppose you are lucky enough to have an internet connection and AppStore access. In that case, you should be able to install a wide range of terminal emulators, programming languages and text editors on your device. Otherwise, follow the manual for JS-enabled devices.

## Built-in tools
Unlike Android, iOS 12 and newer is shipped with a simple scripting tool called Shortcuts. It allows you to perform some minimal computing on the device. Still, it probably won't allow you to use the full computing potential of your device.

# KaiOS phones
KaiOS devices are surprisingly widespread. They are running Firefox's browser engine, Gecko, on top of modified Linux. The devices allow application sideloading, so you don't need internet access to install a new application. There doesn't seem to be any applications for coding on KaiOS, though. So you might be better off checking the manual for JS-enabled devices.

# Windows phones

# Symbian phones

# Blackberry phones

# Java MIDP-compatible phones
