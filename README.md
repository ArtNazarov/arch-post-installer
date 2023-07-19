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

[Telegram:ArtNazarov](https://telegram.me/ArtNazarov)
