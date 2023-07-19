# arch-post-installer
gui tool for arch post install

Supports installation for deb and rpm distributions

Added deb/rpm scripts for:

- dbus broker
- Vulkan
- Port Proton
- Wine
- Developer tools
- PulseAudio
- PipeWire
- Alsa
- Bluetooth
- Audio players
- Internet tools
- Messengers
- Security tools
- Flatpak
- Snap

new ui with tabs by categories 

![image](https://drive.google.com/uc?export=view&id=1vQ_zDkDlwFfrtRrmsdF9ZB8GzGp6ndN_)

![image](https://drive.google.com/uc?export=view&id=1yjQfSxm5H00DjZS6cUXVAYd9LX67ev-J)
 
![image](https://drive.google.com/uc?export=view&id=1LyGRqYd3rr_kMlznW2gQ35bK-nZ2kKTU)

Note:

Add user to sudoer/wheel group during postinstallation for skipping password.

```
sudo usermod -aG wheel $USER
```

uncomment or add lines in /etc/sudoers using sudo nano /etc/sudoers

```
## Same thing without a password
%wheel ALL=(ALL:ALL) NOPASSWD: ALL

## Uncomment to allow members of group sudo to execute any command
%sudo ALL=(ALL:ALL) NOPASSWD: ALL
```

How to build from sources
==

![build](https://drive.google.com/uc?export=view&id=1qY9R2Gce6nPiEzKV_XZiC_Y9V0wCQ4JO)


1. Install QtCreator and cmake (from extra/cmake)

2. Launch in project folder cmake tool

```
$ cmake .
```

2. Launch compilation

```
$ make
```

3. To install build (will installed into /usr/local/bin/)

```
$ sudo make install
```

[Telegram:ArtNazarov](https://telegram.me/ArtNazarov)
