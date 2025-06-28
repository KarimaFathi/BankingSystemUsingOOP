# 🏦 Banking System Using OOP in C++

This project is a fully featured **console-based banking system** implemented in C++, redesigned from a simpler client management app :👉 **[BankWithCPP](https://github.com/KarimaFathi/BankWithCPP)**. It uses **Object-Oriented Programming (OOP)** principles to ensure modularity, reusability, and scalability, This version significantly enhances the functionality using clean OOP architecture and adds:

💳 Transactions (Deposit, Withdraw, Transfer)

👥 Multi-user support with login and role-based permissions

🌐 Currency exchange simulation

📝 Historical logs (Login + Transfers)

🎛 Modular design for easier scalability

## 🧩 Features

### ✅ Core Banking Features
- **Client Management**
  - Add, update, delete, find clients
  - View full client list
- **Transactions**
  - Deposit and withdraw funds
  - Transfer between clients
  - View total balances
- **Currency Tools**
  - Convert between currencies
  - Update exchange rates
  - Find specific currency details

### 👥 User Management
- Login system with credential check
- Role-based access control (admin vs limited user)
- Lock system after **3 failed login attempts**
- Passwords are **encrypted** when stored in `users.txt`
- Track login sessions
- Add/update/delete users
- View user details and list

### 📊 Logs and Tracking
- Login logs stored in `loginRegister.txt`
- Transfer history in `transferLog.txt`
- All data is persistently stored in `.txt` files
