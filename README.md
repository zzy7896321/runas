# runas

Uasge: ./runas <program_path>

Build an executable that runs a program as the current user. The output's name is `$(basename program_path)-$USR`.

The build script will build the C program owned by the current user and set its setuid bit. This might be useful for running a script as a different user in the system. However, use with caution because anyone with r-x can execute that command as the current user!
