#include <iostream>
using namespace std;
#include <cctype>
#include <random>
#include <chrono>
#include <thread>
using u32 = uint_least32_t;
using engine = std::mt19937;

#define misilesIniciales 15;
#define avionesIniciales 5;
struct tipoJugador
{
    string nombre;
    int aviones;
    int fallos;
    int misiles;
    int AS;
    char tablero[5][5];
};
void limpiarPantalla()
{

#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#elif defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");

#elif defined(__APPLE__)
    system("clear");
#endif
}
void esperarXMiliSegundosParaSeguir(int x)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(x));
}
void enterParaSeguir()
{
    cout << "\n"
         << endl;
    cout << "--ENTER--" << endl;
    cin.get();
    cout << "\n"
         << endl;
}
void enterParaLimpiar()
{
    cout << "\n"
         << endl;
    cout << "--ENTER--" << endl;
    cin.get();
    limpiarPantalla();
    cout << "\n"
         << endl;
}
void mostrarCartelDados()
{
    cout << "\n"
         << R"(
       .-------.    ______
      /   o   /|   /\     \
     /_______/o|  /o \  o  \
     | o     | | /   o\_____\
     |   o   |o/ \o   /o    /
     |     o |/   \ o/  o  /
     '-------'     \/____o/
 )"
         << "\n"
         << endl;
}
void mostrarMisil()
{

    cout << "\n"
         << R"(
          /\         
         /  \    
         |  |     
         |  |     
        / == \    
        |/**\|    
         ||||  
    )"
         << "\n"
         << endl;
}
void mostrarMandarMisil()
{
    limpiarPantalla();
    cout << "ENVIANDO MISIL!!!\n"
         << endl;
    cout << "\n"
         << R"(
          /\         
         /  \    
         |  |     
         |  |     
        / == \    
        |/**\|    
         ||||  
    )"
         << "\n"
         << endl;
    esperarXMiliSegundosParaSeguir(900);
}
void mostrarCartelTableroUno()
{
    cout << "\n"
         << R"(
    ████████╗ █████╗ ██████╗ ██╗     ███████╗██████╗  ██████╗          ██╗ ██╗
    ╚══██╔══╝██╔══██╗██╔══██╗██║     ██╔════╝██╔══██╗██╔═══██╗         ██║███║
       ██║   ███████║██████╔╝██║     █████╗  ██████╔╝██║   ██║         ██║╚██║
       ██║   ██╔══██║██╔══██╗██║     ██╔══╝  ██╔══██╗██║   ██║    ██   ██║ ██║
       ██║   ██║  ██║██████╔╝███████╗███████╗██║  ██║╚██████╔╝    ╚█████╔╝ ██║
       ╚═╝   ╚═╝  ╚═╝╚═════╝ ╚══════╝╚══════╝╚═╝  ╚═╝ ╚═════╝      ╚════╝  ╚═╝
   )"
         << "\n"

         << endl;
}
void mostrarCartelTableroDos()
{
    cout << "\n"
         << R"(
    ████████╗ █████╗ ██████╗ ██╗     ███████╗██████╗  ██████╗          ██╗██████╗ 
    ╚══██╔══╝██╔══██╗██╔══██╗██║     ██╔════╝██╔══██╗██╔═══██╗         ██║╚════██╗
       ██║   ███████║██████╔╝██║     █████╗  ██████╔╝██║   ██║         ██║ █████╔╝
       ██║   ██╔══██║██╔══██╗██║     ██╔══╝  ██╔══██╗██║   ██║    ██   ██║██╔═══╝ 
       ██║   ██║  ██║██████╔╝███████╗███████╗██║  ██║╚██████╔╝    ╚█████╔╝███████╗
       ╚═╝   ╚═╝  ╚═╝╚═════╝ ╚══════╝╚══════╝╚═╝  ╚═╝ ╚═════╝      ╚════╝ ╚══════╝
                                                                                
   )"
         << "\n"

         << endl;
}
void mostrarTitulo()
{
    cout << "\n"
         << R"(
██████   █████  ████████  █████  ██      ██       █████       █████  ███████ ██████  ███████  █████  
██   ██ ██   ██    ██    ██   ██ ██      ██      ██   ██     ██   ██ ██      ██   ██ ██      ██   ██ 
██████  ███████    ██    ███████ ██      ██      ███████     ███████ █████   ██████  █████   ███████ 
██   ██ ██   ██    ██    ██   ██ ██      ██      ██   ██     ██   ██ ██      ██   ██ ██      ██   ██ 
██████  ██   ██    ██    ██   ██ ███████ ███████ ██   ██     ██   ██ ███████ ██   ██ ███████ ██   ██ 
)"
         << "\n"

         << endl;
}
void mostrarChoque()
{
    limpiarPantalla();
    cout << "\n"
         << R"(

              _.-^^---....,,---_
           _--                  --_
          <          BOOM!         >)
           \._                   _./
              ```--. . , ; .--'''
                    | |   |
                 .-=||  | |=-.
                 `-=#$%&%$#=-'
                    | ;  :|
           _____.,-#%&$@%#&#~,._____

    )"
         << "\n"
         << endl;
    esperarXMiliSegundosParaSeguir(1500);
}
void mostrarMisilLauncher()
{
    cout << "\n"
         << R"(
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⡀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⣾⣿⠟⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣴⣿⣧⡈⠛⠁⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣾⣿⣿⠿⠋⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣴⣿⣿⡿⠛⢁⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣴⣾⣿⡿⠟⢁⣤⠞⠋⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣾⣿⣿⠟⢉⣠⠶⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⢠⣴⣶⣿⠖⢀⣠⠾⣿⣿⠿⠋⣠⡴⠛⠁⠴⠞⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠙⠋⣠⡴⠛⢁⡴⠞⠁⠀⠚⠉⠀⠀⠀⢰⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⣤⠈⢁⣤⠞⢋⣤⡄⠀⠀⠀⠀⠀⠀⢠⣬⣤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠈⠷⠀⠠⣾⣿⡿⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠘⠋⠀⠀⠀⠀⠀⠀⢀⡆⢸⣿⣿⠀⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⠟⠁⠀⠀⠀⠀⠙⢷⣄⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣀⣉⣁⡀⠀⠀⠀⠀⠀⠀⣀⣉⣀⣀⣀⡀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠉⠉⠉⠁⠀⠀⠀⠀⠀⠀⠉⠉⠉⠉⠉⠁⠀⠀⠀
    )"
         << "\n"
         << endl;
}
void mostrarFin()
{
    cout << "\n"
         << R"( 
 ▄████  ▄▄▄       ███▄ ▄███▓▓█████     ▒█████   ██▒   █▓▓█████  ██▀███  
 ██▒ ▀█▒▒████▄    ▓██▒▀█▀ ██▒▓█   ▀    ▒██▒  ██▒▓██░   █▒▓█   ▀ ▓██ ▒ ██▒
▒██░▄▄▄░▒██  ▀█▄  ▓██    ▓██░▒███      ▒██░  ██▒ ▓██  █▒░▒███   ▓██ ░▄█ ▒
░▓█  ██▓░██▄▄▄▄██ ▒██    ▒██ ▒▓█  ▄    ▒██   ██░  ▒██ █░░▒▓█  ▄ ▒██▀▀█▄  
░▒▓███▀▒ ▓█   ▓██▒▒██▒   ░██▒░▒████▒   ░ ████▓▒░   ▒▀█░  ░▒████▒░██▓ ▒██▒
 ░▒   ▒  ▒▒   ▓▒█░░ ▒░   ░  ░░░ ▒░ ░   ░ ▒░▒░▒░    ░ ▐░  ░░ ▒░ ░░ ▒▓ ░▒▓░
  ░   ░   ▒   ▒▒ ░░  ░      ░ ░ ░  ░     ░ ▒ ▒░    ░ ░░   ░ ░  ░  ░▒ ░ ▒░
░ ░   ░   ░   ▒   ░      ░      ░      ░ ░ ░ ▒       ░░     ░     ░░   ░ 
      ░       ░  ░       ░      ░  ░       ░ ░        ░     ░  ░   ░     
                                                     ░                   )"
         << "\n"
         << endl;
}
void mostrarJugadorUno()
{
    cout << "\n"
         << R"( 
     ██╗██╗   ██╗ ██████╗  █████╗ ██████╗  ██████╗ ██████╗     ██╗   ██╗███╗   ██╗ ██████╗ 
     ██║██║   ██║██╔════╝ ██╔══██╗██╔══██╗██╔═══██╗██╔══██╗    ██║   ██║████╗  ██║██╔═══██╗
     ██║██║   ██║██║  ███╗███████║██║  ██║██║   ██║██████╔╝    ██║   ██║██╔██╗ ██║██║   ██║
██   ██║██║   ██║██║   ██║██╔══██║██║  ██║██║   ██║██╔══██╗    ██║   ██║██║╚██╗██║██║   ██║
╚█████╔╝╚██████╔╝╚██████╔╝██║  ██║██████╔╝╚██████╔╝██║  ██║    ╚██████╔╝██║ ╚████║╚██████╔╝
 ╚════╝  ╚═════╝  ╚═════╝ ╚═╝  ╚═╝╚═════╝  ╚═════╝ ╚═╝  ╚═╝     ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ 
                                                                                           )"
         << "\n"
         << endl;
}
void mostrarCartelGanador()
{
    cout << "\n"
         << R"(
        ██████╗  █████╗ ███╗   ██╗ █████╗ ██████╗  ██████╗ ██████╗ 
        ██╔════╝ ██╔══██╗████╗  ██║██╔══██╗██╔══██╗██╔═══██╗██╔══██╗
        ██║  ███╗███████║██╔██╗ ██║███████║██║  ██║██║   ██║██████╔╝
        ██║   ██║██╔══██║██║╚██╗██║██╔══██║██║  ██║██║   ██║██╔══██╗
        ╚██████╔╝██║  ██║██║ ╚████║██║  ██║██████╔╝╚██████╔╝██║  ██║
         ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝  ╚═╝╚═════╝  ╚═════╝ ╚═╝  ╚═╝
                                                            )"
         << "\n"
         << endl;
}
void mostrarJugadorDos()
{
    cout << "\n"
         << R"( 
     ██╗██╗   ██╗ ██████╗  █████╗ ██████╗  ██████╗ ██████╗     ██████╗  ██████╗ ███████╗
     ██║██║   ██║██╔════╝ ██╔══██╗██╔══██╗██╔═══██╗██╔══██╗    ██╔══██╗██╔═══██╗██╔════╝
     ██║██║   ██║██║  ███╗███████║██║  ██║██║   ██║██████╔╝    ██║  ██║██║   ██║███████╗
██   ██║██║   ██║██║   ██║██╔══██║██║  ██║██║   ██║██╔══██╗    ██║  ██║██║   ██║╚════██║
╚█████╔╝╚██████╔╝╚██████╔╝██║  ██║██████╔╝╚██████╔╝██║  ██║    ██████╔╝╚██████╔╝███████║
 ╚════╝  ╚═════╝  ╚═════╝ ╚═╝  ╚═╝╚═════╝  ╚═════╝ ╚═╝  ╚═╝    ╚═════╝  ╚═════╝ ╚══════╝
                                                                                           )"
         << "\n"
         << endl;
}
void mostrarMuerteSubita()
{
    cout << "\n"
         << R"(
 ███▄ ▄███▓ █    ██ ▓█████  ██▀███  ▄▄▄█████▓▓█████      ██████  █    ██  ▄▄▄▄    ██▓▄▄▄█████▓ ▄▄▄      
▓██▒▀█▀ ██▒ ██  ▓██▒▓█   ▀ ▓██ ▒ ██▒▓  ██▒ ▓▒▓█   ▀    ▒██    ▒  ██  ▓██▒▓█████▄ ▓██▒▓  ██▒ ▓▒▒████▄    
▓██    ▓██░▓██  ▒██░▒███   ▓██ ░▄█ ▒▒ ▓██░ ▒░▒███      ░ ▓██▄   ▓██  ▒██░▒██▒ ▄██▒██▒▒ ▓██░ ▒░▒██  ▀█▄  
▒██    ▒██ ▓▓█  ░██░▒▓█  ▄ ▒██▀▀█▄  ░ ▓██▓ ░ ▒▓█  ▄      ▒   ██▒▓▓█  ░██░▒██░█▀  ░██░░ ▓██▓ ░ ░██▄▄▄▄██ 
▒██▒   ░██▒▒▒█████▓ ░▒████▒░██▓ ▒██▒  ▒██▒ ░ ░▒████▒   ▒██████▒▒▒▒█████▓ ░▓█  ▀█▓░██░  ▒██▒ ░  ▓█   ▓██▒
░ ▒░   ░  ░░▒▓▒ ▒ ▒ ░░ ▒░ ░░ ▒▓ ░▒▓░  ▒ ░░   ░░ ▒░ ░   ▒ ▒▓▒ ▒ ░░▒▓▒ ▒ ▒ ░▒▓███▀▒░▓    ▒ ░░    ▒▒   ▓▒█░
░  ░      ░░░▒░ ░ ░  ░ ░  ░  ░▒ ░ ▒░    ░     ░ ░  ░   ░ ░▒  ░ ░░░▒░ ░ ░ ▒░▒   ░  ▒ ░    ░      ▒   ▒▒ ░
░      ░    ░░░ ░ ░    ░     ░░   ░   ░         ░      ░  ░  ░   ░░░ ░ ░  ░    ░  ▒ ░  ░        ░   ▒   
       ░      ░        ░  ░   ░                 ░  ░         ░     ░      ░       ░                 ░  ░
                                                                               ░                        )"
         << "\n"
         << endl;
}
void mostrarColisionAs()
{
    limpiarPantalla();
    cout << "\n"
         << R"(
     ▄████▄   ▒█████   ██▓     ██▓  ██████  ██▓ ▒█████   ███▄    █ 
    ▒██▀ ▀█  ▒██▒  ██▒▓██▒    ▓██▒▒██    ▒ ▓██▒▒██▒  ██▒ ██ ▀█   █ 
    ▒▓█    ▄ ▒██░  ██▒▒██░    ▒██▒░ ▓██▄   ▒██▒▒██░  ██▒▓██  ▀█ ██▒
    ▒▓▓▄ ▄██▒▒██   ██░▒██░    ░██░  ▒   ██▒░██░▒██   ██░▓██▒  ▐▌██▒
    ▒ ▓███▀ ░░ ████▓▒░░██████▒░██░▒██████▒▒░██░░ ████▓▒░▒██░   ▓██░
    ░ ░▒ ▒  ░░ ▒░▒░▒░ ░ ▒░▓  ░░▓  ▒ ▒▓▒ ▒ ░░▓  ░ ▒░▒░▒░ ░ ▒░   ▒ ▒ 
    ░  ▒     ░ ▒ ▒░ ░ ░ ▒  ░ ▒ ░░ ░▒  ░ ░ ▒ ░  ░ ▒ ▒░ ░ ░░   ░ ▒░
    ░        ░ ░ ░ ▒    ░ ░    ▒ ░░  ░  ░   ▒ ░░ ░ ░ ▒     ░   ░ ░ 
    ░ ░          ░ ░      ░  ░ ░        ░   ░      ░ ░           ░ 
    ░      
    )"
         << "\n"
         << endl;
    esperarXMiliSegundosParaSeguir(1500);

    cout << "\n"
         << R"(

              _.-^^---....,,---_
           _--                  --_
          <          BOOM!         >)
           \._                   _./
              ```--. . , ; .--'''
                    | |   |
                 .-=||  | |=-.
                 `-=#$%&%$#=-'
                    | ;  :|
           _____.,-#%&$@%#&#~,._____

    )"
         << "\n"
         << endl;
    cout << "DOS AVIONES HAN CHOCADO!!" << endl;
    esperarXMiliSegundosParaSeguir(1500);
}
void mostrarAs()
{
    limpiarPantalla();
    cout << "\n"
         << R"(
            _____                _   _                _       
     /\    / ____|     /\       | | (_)              | |      
    /  \  | (___      /  \   ___| |_ ___   ____ _  __| | ___  
   / /\ \  \___ \    / /\ \ / __| __| \ \ / / _` |/ _` |/ _ \ 
  / ____ \ ____) |  / ____ \ (__| |_| |\ V / (_| | (_| | (_) |
 /_/    \_\_____/  /_/    \_\___|\__|_| \_/ \__,_|\__,_|\___/ 
)"
         << "\n"
         << R"(              
                              ._                             
                              |* ;                            
            `*-.              |"":                            
             \  \             |""                             
              .  \            |   :                           
              `   \           |                               
               \   \          |    ;               +.         
                .   \         |                   *._`-.      
                `    \        |     :          .-*'  `. `.    
                _\    \.__..--**--...L_   _.-*'      .'`*'    
               /  `*-._\   -.       .-*"*+._       .'         
              :        ``*-._*.     \      _J.   .'           
          .-*'`*-.       ;     `.    \    /   `.'             
      .-*'  _.-*'.     .-'       `-.  `-.:   _.'`-.           
   +*' _.-*'      `..-'             `*-. `**'      `-.        
    `*'          .-'      ._            `*-._         `.      
              .-'         `.`-.____..+-**""'         .*"`.    
         ._.-'          _.-*'':$$$;._$              /     `.  
      .-'  `.      _.-*' `*-.__T$P   `"**--..__    :        `.
.'..-'       \_.-*'                            `"**--..___.-*'
`. `.    _.-*'                                                
  `. `:*'                                                     
    `. `.                                                     
      `*
)"
         << "\n"
         << endl;
    esperarXMiliSegundosParaSeguir(1500);
}

void destruirAvion(char (&tablero)[5][5], int x, int y)
{
    tablero[x][y] = 'X';
    x = x + 1;
    y = y + 1;
    cout << "Avion abatido en fila " << x << " columna " << y << endl;
}
int lanzarDados()
{
    // Funcion encargada de generar numeros al azar para la tirada de dados
    std::random_device os_seed;
    const u32 seed = os_seed();

    engine generator(seed);
    std::uniform_int_distribution<u32> distribute(1, 6);

    return distribute(generator);
}
void mostrarMisilFallido()
{
    cout << "\n"
         << endl;
    cout << "------------------- NO HAY AVIONES EN ESTA POSICION ----------------------" << endl;
    cout << "\n"
         << endl;
}
void mostrarTableroFilasYColumnas(char (&tablero)[5][5])
{
    // procedimiento para mostrar el tablero con filas y columnas al jugador
    cout << "  \t   1    2    3    4    5  " << endl;
    cout << endl;
    for (int i = 0; i < 5; i++)
    {
        int j = i + 1;
        cout << "  " << j << "\t";
        cout << "|";
        for (int j = 0; j < 5; j++)
        {
            cout << "  "
                 << tablero[i][j]
                 << "  ";
        }
        cout << "|";
        cout << "\n";
    }
    cout << endl;
}

void mostrarTableroFilas(char (&tablero)[5][5])
{
    // procedimiento para mostrar las filas del tablero al jugador
    cout << "\t" << endl;
    cout << endl;
    for (int i = 0; i < 5; i++)
    {
        int j = i + 1;
        cout << "  " << j << "\t";
        cout << "|";
        for (int j = 0; j < 5; j++)
        {
            cout << "  "
                 << tablero[i][j]
                 << "  ";
        }
        cout << "|";
        cout << "\n";
    }
    cout << endl;
}
void mostrarTableroColumnas(char (&tablero)[5][5])
{
    // procedimiento para mostrar las columnas del tablero al jugador
    cout << "  \t   1    2    3    4    5  " << endl;
    cout << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "  \t|";
        for (int j = 0; j < 5; j++)
        {
            cout << "  "
                 << tablero[i][j]
                 << "  ";
        }
        cout << "|";
        cout << "\n";
    }
    cout << endl;
}
void mostrarJugadorPorNumero(int numeroJugador)
{
    if (numeroJugador == 1)
    {
        mostrarJugadorUno();
    }
    else
    {
        mostrarJugadorDos();
    }
}
void mostrarErrorPosicionOcupada(int numeroJugador)
{
    limpiarPantalla();
    mostrarJugadorPorNumero(numeroJugador);
    cout << "---- ERROR ----" << endl;
    cout << "\n"
         << endl;
    cout << "Ya hay un avion en la posicion elegida, intenta denuevo " << endl;
    enterParaSeguir();
}
void mostrarErrorPosicionInvalida(int numeroJugador)
{

    limpiarPantalla();
    mostrarJugadorPorNumero(numeroJugador);
    cout << "---- ERROR ----" << endl;
    cout << "\n"
         << endl;
    cout << "La posición seleccionada no es valida, intenta denuevo." << endl;
    enterParaSeguir();
}
void mostrarAvionesIngresados(int i)
{
    int avionesRestantes;
    avionesRestantes = 5 - i;
    cout << "AVIONES RESTANTES: " << avionesRestantes << endl;
    cout << "\n"
         << endl;
}
int ingresarFilaPorJugador(int numeroJugador, char (&tableroJ)[5][5], int i)
{
    int fila;
    mostrarJugadorPorNumero(numeroJugador);
    mostrarAvionesIngresados(i);

    mostrarTableroFilas(tableroJ);
    cout << "Selecciona el número de fila: ";
    cin >> fila;
    return fila;
}
int ingresarColumnaPorJugador(int numeroJugador, char (&tableroJ)[5][5], int i)
{
    int columna;
    mostrarJugadorPorNumero(numeroJugador);
    mostrarAvionesIngresados(i);

    mostrarTableroColumnas(tableroJ);
    cout << "Selecciona el número de columna: ";
    cin >> columna;
    return columna;
}

void introducirAviones(char (&tableroJ)[5][5], int numeroJugador)
{
    int fila, columna;
    bool posicionIncorrecta;
    for (int i = 0; i < 5; i++)
    {
        posicionIncorrecta = true;

        do
        {
            limpiarPantalla();
            fila = ingresarFilaPorJugador(numeroJugador, tableroJ, i);
            limpiarPantalla();
            columna = ingresarColumnaPorJugador(numeroJugador, tableroJ, i);
            int x = fila - 1;
            int y = columna - 1;
            char pos = tableroJ[x][y];
            cin.get();
            if (pos == '>')
            {
                posicionIncorrecta = true;
                mostrarErrorPosicionOcupada(numeroJugador);
            }
            else
            {
                if (fila <= 0 || fila > 5 || columna <= 0 || columna > 5)
                {
                    posicionIncorrecta = true;
                    mostrarErrorPosicionInvalida(numeroJugador);
                }
                else
                {
                    posicionIncorrecta = false;
                }
            }
        } while (posicionIncorrecta);
        fila = fila - 1;
        columna = columna - 1;
        tableroJ[fila][columna] = '>';
    };
}
void mostrarTableroOponente(char (&tablero)[5][5])
{
    // procedimiento para mostrar el tablero del oponente (sus aviones se ocultan)
    cout << "  \t   1    2    3    4    5  " << endl;
    cout << endl;
    for (int i = 0; i < 5; i++)
    {
        int h = i + 1;
        cout << "  " << h << "\t";
        cout << "|";
        for (int j = 0; j < 5; j++)
        {
            if (tablero[i][j] == '>')
            {
                cout << "  "
                     << "-"
                     << "  ";
            }
            else
            {

                cout << "  "
                     << tablero[i][j]
                     << "  ";
            }
        }
        cout << "|";
        cout << "\n";
    }
    cout << endl;
}
void mostrarInstrucciones()
{
    string stop;
    cout << R"(

OBJETIVO
---------------

Batalla Aérea es un juego de guerra. El jugador que destruya más aviones (o todos) antes de que se acaben sus misiles, es el ganador.

)"
         << "\n"
         << endl;
    enterParaSeguir();
    mostrarMisil();
    cout
        << R"(
MODO DE JUEGO
-------------------------

Se empieza con cada jugador tirando los dados, el que saque el mayor número será el Jugador 1 y el otro el Jugador 2.
 
Cada jugador va a contar con un tablero de 5x5, donde colocarán sus 5 aviones de combate en cualquier posición de forma SECRETA. 
Símbolos que aparecerán en tu tablero:
 - Ubicación de tus aviones     " > "
 - Resto del tablero            " - "

El jugador que empieza ve una copia del mapa del enemigo. Elige las coordenadas de ataque y envía un misil. 
Símbolos que aparecerán en el tablero enemigo:
 - Si se acierta la posición del avión enemigo    " X "
 - Si no has atacado esa posición o no acertaste  " - "

)"
        << "\n"
        << endl;
    enterParaSeguir();
    cout << R"(
MECANICA ESPECIAL " AS "
----------------------------------
La  mecánica consiste en la activación del modo As del piloto, se da cuando el jugador acierta la posición de un avión oponente convirtiéndolo en objetivo. 
Si este modo se activa (se da de forma aleatoria, es decir, se puede activar o no) el objetivo logra esquivar el misil que se dirige hacia él, y se mueve a una casilla ADYACENTE que  también se da de forma aleatoria. 
Si el movimiento fue a una casilla donde ya se encontraba un avión, ambos se destruirán. 
Si no se activa AS el misil continúa su trayectoria destruyendo el avión del oponente

Este efecto no se puede activar más de 3 veces por jugador.

Sí, este modo puede afectar a vos o a tu oponente. ¡¡Piensa bien donde pones tus aviones!!

)"
         << "\n"
         << endl;
    enterParaSeguir();
    mostrarMuerteSubita();
    cout << R"(
MUERTE SÚBITA:

Si ocurre un empate, se entra en muerte súbita donde cada uno disparará un misil y el primero que destruya un avión ¡Gana!


)"
         << "\n"
         << endl;
}
void mostrarDados(int dadosJ, string nombre)
{
    // procedimiento para mostrar los dados de un jugador

    cout << "\tDADOS: " << nombre << " saco " << dadosJ << " (1-6)" << endl;
}
void mostrarGanador(tipoJugador ganador)
{
    // procedimiento para mostrar al ganador
    mostrarCartelGanador();
    cout << "\t\t==============================================" << endl;
    cout << "\n"
         << endl;
    cout << "\t\t-------------------"
         << ganador.nombre
         << "--------------------" << endl;
    cout << "\n"
         << endl;

    cout << "\t\t==============================================" << endl;
}

void mostrarMensajeDeAtaque(int numeroJugador)
{
    if (numeroJugador == 1)
    {
        mostrarJugadorUno();
    }
    else
    {
        mostrarJugadorDos();
    }
    cout << "Tu turno de atacar" << endl;
    mostrarMisilLauncher();
}

void mostrarEstadisticas(tipoJugador(&J), int misilesExtras)
{
    // procedimiento para mostrar las estadisticas de un jugador

    int misilesGastados, avionesGolpeados;
    cout << "- Estadisticas -" << endl;
    cout << "Nombre: " << J.nombre << endl;
    cout << "Aviones que sobrevivieron: " << J.aviones << endl;
    cout << "Cantidad de veces que los misiles no dieron en el blanco: " << J.fallos << endl;
    cout << "Cantidad de AS activados: " << J.AS << endl;
}
void enviarMisil(tipoJugador(&jugador), tipoJugador(&oponente), char (&tableroOponente)[5][5], int x, int y, bool(&avionDestruido))
{
    char pos = tableroOponente[x][y];
    mostrarMandarMisil();
    if (pos == '>')
    {
        mostrarChoque();
        destruirAvion(tableroOponente, x, y);
        esperarXMiliSegundosParaSeguir(1500);

        oponente.aviones = oponente.aviones - 1;
        avionDestruido = true;
    }
    else if (pos == '-')
    {
        jugador.fallos++;
        mostrarMisilFallido();
        esperarXMiliSegundosParaSeguir(1500);
    }
    else
    {
        cout << "El avion al que le disparas ya esta muerto!" << endl;
        esperarXMiliSegundosParaSeguir(1500);
    }
    jugador.misiles = jugador.misiles - 1;
}
void dirigirAtaque(int (&ataque)[2])
{
    int fila, columna;
    do
    {
        cout << "Elegir fila:\t";
        cin >> fila;
        cout << "\n"
             << endl;
        cout << "Elegir columna:\t";
        cin >> columna;
        cout << "\n"
             << endl;
        enterParaSeguir();
        if (fila <= 0 || columna <= 0 || columna > 5 || fila > 5)
        {
            cout << "La fila y/o columna introducida/s no es/son validas" << endl;
            cout << "Intenta denuevo" << endl;
            enterParaSeguir();
        }
    } while (fila <= 0 || columna <= 0 || columna > 5 || fila > 5);
    fila = fila - 1;
    columna = columna - 1;
    ataque[0] = fila;
    ataque[1] = columna;
}
void usarAS(char (&tablero)[5][5], int x, int y)
{
    int suerte, ant_x, ant_y;
    ant_x = x;
    ant_y = y;
    bool choque = false;
    suerte = lanzarDados();
    tablero[x][y] = '-';
    if (suerte == 1)
    {
        // El avion se mueve para arriba
        if (x == 0)
        {
            x = 4;
        }
        else
        {
            x = x - 1;
        }
    }
    else if (suerte == 6)
    {
        // El avion se mueve para abajo
        if (x == 4)
        {
            x = 0;
        }
        else
        {
            x = x + 1;
        }
    }
    else if (suerte == 3 || suerte == 2)
    {
        // El avion se mueve para la derecha
        if (y == 4)
        {
            y = 0;
        }
        else
        {
            y = y + 1;
        }
    }
    else
    {
        // El avion se mueve para la izquierda
        if (y == 0)
        {
            y = 4;
        }
        else
        {
            y = y - y;
        }
    }
    if (tablero[x][y] == '>')
    {
        mostrarColisionAs();
        destruirAvion(tablero, ant_x, ant_y);
        destruirAvion(tablero, x, y);
        esperarXMiliSegundosParaSeguir(1500);
    }
    else
    {
        tablero[x][y] = '>';
    }
}
bool calcularSiASFueActivado()
{
    // Funcion encargada de calcular si se activo un AS, la posibilidad es de 1 entre 6
    int numeroDeLaSuerte = lanzarDados();
    if (numeroDeLaSuerte == 1 || numeroDeLaSuerte == 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void jugar(int numeroJugador, tipoJugador(&jugador), tipoJugador(&oponente), char (&tableroJugador)[5][5], char (&tableroOponente)[5][5], bool muerteSubita, tipoJugador(&ganador))
{
    bool seActivoAS, avionDestruido;
    int ataque[2] = {};
    // juego principal
    mostrarMensajeDeAtaque(numeroJugador);
    esperarXMiliSegundosParaSeguir(750);

    if (!muerteSubita)
    {
        cout << "MISILES DISPONIBLES: " << jugador.misiles << endl;
        cout << "\n"
             << endl;
    }
    if (oponente.AS == 3)
    {
        cout << "--- AS del OPONENTE agotados ---" << endl;
        cout << "\n"
             << endl;
    }
    mostrarTableroOponente(tableroOponente);
    cout << "\n"
         << endl;
    dirigirAtaque(ataque);
    int x = ataque[0];
    int y = ataque[1];
    if (muerteSubita)
    {
        avionDestruido = false;
        enviarMisil(jugador, oponente, tableroOponente, x, y, avionDestruido);
        if (avionDestruido)
        {
            ganador = jugador;
        }
    }
    else
    {
        int AS = oponente.AS;
        char pos = tableroOponente[x][y];
        if (pos == '>' && AS < 3)
        {

            seActivoAS = calcularSiASFueActivado();

            if (seActivoAS)
            {
                mostrarAs();
                oponente.AS++;
                usarAS(tableroOponente, x, y);
            };
        };
        enviarMisil(jugador, oponente, tableroOponente, x, y, avionDestruido);
        int avionesOp = oponente.aviones;
        if (avionesOp == 0)
        {
            ganador = jugador;
        }
    }
}

void mostrarJugador(tipoJugador J, int numeroJugador)
{
    // Procedimiento para mostrar datos del jugador
    mostrarJugadorPorNumero(numeroJugador);
    cout << "Nombre: " << J.nombre << endl;
    cout << "Aviones: " << J.aviones << endl;
    cout << "Misiles Disponibles: " << J.misiles << endl;
    cout << "AS activados: " << J.AS << endl;
    cout << "\n"
         << endl;
    cin.get();
}
void pedirNombre(string(&nombre), int numeroJugador)
{
    // Procedimiento para obtener el nombre de un jugador
    string temp;
    cout << "Introducir nombre del jugador " << numeroJugador << " (SIN ESPACIOS):\t";
    cin >> temp;
    nombre = temp;
}
tipoJugador generarJugador(int numeroJugador)
{
    // Funcion encargada de crear un nuevo jugador
    tipoJugador j;

    string nombre;
    pedirNombre(nombre, numeroJugador);
    j.nombre = nombre;
    j.aviones = avionesIniciales;
    j.fallos = 0;
    j.misiles = misilesIniciales;
    j.AS = 0;
    limpiarPantalla();

    return j;
}
void generarTableroVacio(char (&tablero)[5][5])
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            tablero[i][j] = '-';
        };
    };
}

bool ningunJugadorPerdio(int avionesJ1, int avionesJ2)
{
    if (avionesJ1 > 0 && avionesJ2 > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool quedanMisiles(int misilesJ1, int misilesJ2)
{
    if (misilesJ1 > 0 && misilesJ2 > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    limpiarPantalla();
    // Programa principal
    int misiles, misilesExtras1, misilesExtras2, avionesJ1, avionesJ2, dadosJ1, dadosJ2;
    string stop, tableroJugador;
    bool turnoJ1;
    tipoJugador ganador, jugador;

    // Mostramos instrucciones
    mostrarTitulo();
    mostrarInstrucciones();
    enterParaLimpiar();

    // Generamos los jugadores
    // Mostramos los datos iniciales de los jugadores
    tipoJugador J1 = generarJugador(1);
    limpiarPantalla();
    mostrarJugador(J1, 1);
    enterParaLimpiar();
    tipoJugador J2 = generarJugador(2);
    mostrarJugador(J2, 2);
    enterParaLimpiar();

    // Generamos el tablero para cada jugador
    char tableroJ1[5][5] = {};
    char tableroJ2[5][5] = {};
    generarTableroVacio(tableroJ1);
    generarTableroVacio(tableroJ2);

    // Cada jugador introduce sus aviones en sus respectivos tableros
    introducirAviones(tableroJ1, 1);
    limpiarPantalla();
    mostrarJugadorUno();
    mostrarTableroFilasYColumnas(tableroJ1);
    enterParaLimpiar();
    introducirAviones(tableroJ2, 2);
    limpiarPantalla();
    mostrarJugadorDos();
    mostrarTableroFilasYColumnas(tableroJ2);
    enterParaLimpiar();

    // Lanzamos los dados para ver quien comienza
    dadosJ1 = 0;
    dadosJ2 = 0;
    do
    {
        cout << "----LANZANDO DADOS----"
             << "\n"
             << endl;
        mostrarCartelDados();
        dadosJ1 = lanzarDados();
        mostrarDados(dadosJ1, J1.nombre);
        cout << "\n"
             << endl;
        dadosJ2 = lanzarDados();
        mostrarDados(dadosJ2, J2.nombre);
        cout << "\n"
             << endl;
        if (dadosJ1 == dadosJ2)
        {
            cout << "Ocurrio un empate, lanzar dados denuevo..." << endl;
            enterParaLimpiar();
            esperarXMiliSegundosParaSeguir(500);
        }
    } while (dadosJ1 == dadosJ2 || dadosJ1 == 0 || dadosJ2 == 0);

    // Definimos como va a ser el orden de juego
    if (dadosJ1 > dadosJ2)
    {
        cout << "\t---------- " << J1.nombre << " EMPIEZA "
             << "----------" << endl;
        turnoJ1 = true;
    }
    else
    {
        cout << "\t---------- " << J2.nombre << " EMPIEZA "
             << "----------" << endl;
        turnoJ1 = false;
    };
    enterParaLimpiar();
    // Declaramos unas variables utiles para el juego
    bool muerteSubita = false;
    bool ganoMuerteSubita = false;

    misilesExtras1 = 0;
    misilesExtras2 = 0;
    // Iniciamos el bucle del juego con el jugador que tenga los dados mas altos
    while (quedanMisiles(J1.misiles, J2.misiles) && ningunJugadorPerdio(J1.aviones, J2.aviones))
    {
        limpiarPantalla();
        if (turnoJ1)
        {
            jugar(1, J1, J2, tableroJ1, tableroJ2, muerteSubita, ganador);
        }
        else
        {

            jugar(2, J2, J1, tableroJ2, tableroJ1, muerteSubita, ganador);
        }
        turnoJ1 = !turnoJ1;
    };
    // Si hay empate entramos en muerte subita
    if (ningunJugadorPerdio(J1.aviones, J2.aviones) && J1.aviones == J2.aviones)
    {
        muerteSubita = true;
        mostrarMuerteSubita();
        cout << "Un empate acaba de suceder, esto sera un duelo a MUERTE!!!" << endl;
        cout << "Los AS no estaran permitidos!" << endl;
        cout << "Que gane el mejor" << endl;
        int avionesMuerteSubitaJ1 = J1.aviones;
        int avionesMuerteSubitaJ2 = J2.aviones;
        enterParaLimpiar();
        while (avionesMuerteSubitaJ2 == J2.aviones && avionesMuerteSubitaJ1 == J1.aviones)
        {
            if (turnoJ1)
            {
                jugar(1, J1, J2, tableroJ1, tableroJ2, muerteSubita, ganador);
                turnoJ1 = false;
                misilesExtras1++;
            }
            else
            {

                jugar(2, J2, J1, tableroJ2, tableroJ1, muerteSubita, ganador);
                turnoJ1 = true;
                misilesExtras2++;
            }
            esperarXMiliSegundosParaSeguir(1500);
            limpiarPantalla();
        }
    }

    // Mostramos el resultado
    limpiarPantalla();
    mostrarGanador(ganador);
    enterParaLimpiar();
    mostrarJugadorUno();
    mostrarEstadisticas(J1, misilesExtras1);
    enterParaSeguir();
    mostrarJugadorDos();
    mostrarEstadisticas(J2, misilesExtras2);
    enterParaSeguir();
    enterParaLimpiar();
    mostrarFin();

    return 0;
}