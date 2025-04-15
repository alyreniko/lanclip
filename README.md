# LanClip
A C project using the libsodium library for secure clipboard content sharing between devices in the same local network.

📋 **Project Goal**:
Creating a cross-platform C application that:
- Automatically detects other devices in the local network.
- Exchanges public keys.
- Transfers encrypted clipboard content between nodes.
- Encrypts all content during transmission.

---

## 🔐 Cryptography
- [x] Symmetric data encryption
- [x] Asymmetric data encryption
- [ ] Generating a symmetric key for the session
- [ ] Encrypting the symmetric key with the recipient's public key
- [ ] Decrypting the symmetric key with the private key

---

## 🌐 Network
- [ ] Auto-discovery of devices in the local network
- [ ] Establishing a connection between nodes
- [ ] Exchanging public keys during connection setup
- [ ] Transmitting encrypted data

---

## 📋 Clipboard
- [x] Reading clipboard on Linux
- [ ] Reading clipboard on Windows
- [ ] Inserting received content into the local clipboard

---

## 🔧 Dependencies
- libsodium — encryption
- xclip / wl-clipboard (Linux) — clipboard access
