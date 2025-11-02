
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <thread>
#include <chrono>
#include <iostream>
#include <Dibujo.hpp>
#include <GestorDibujos.hpp>
#include <Corral.hpp>
using namespace ftxui;

int main()
{
    auto screen = Screen::Create(
        Dimension::Fixed(80),
        Dimension::Fixed(24));

    const std::vector<std::u32string> cancha = {
        U"  _||_ ",
        U" |    |",
        U" |____|",
        U" |    |",
        U"/-|__|-\\"};

    const std::vector<std::u32string> jugador1 = {
        U"  O  ",
        U" /|\\ ",
        U" / \\ "};

    const std::vector<std::u32string> jugador2 = {
        U"  O  ",
        U" \\|/ ",
        U" / \\ "};

    const std::vector<std::u32string> jugador3 = {
        U"  O  ",
        U" -|- ",
        U" / \\ "};

    const std::vector<std::u32string> jugador4 = {
        U"  O  ",
        U" /|_ ",
        U" / \\ "};

    const std::vector<std::u32string> jugador5 = {
        U"  O  ",
        U" _|\\ ",
        U" / \\ "};

    const std::vector<std::u32string> jugador6 = {
        U"   o__ ",      
        U"  /|     ", 
        U"  / >  O "};

    const std::vector<std::u32string> arbol1 = {
        U"  &&&",
        U" &&&&&",
        U"   |"};

    const std::vector<std::u32string> arbitro = {
        U"  O  ",
        U" /|\\ ",
        U" _|_ "};

    GestorDibujos gestor;
    gestor.Agregar(Dibujo(2, 1, cancha, ftxui::Color::White));        // estructura principal 
    gestor.Agregar(Dibujo(15, 2, arbol1, ftxui::Color::Green));       // árbol
    gestor.Agregar(Dibujo(5, 4, arbol1, ftxui::Color::Green));        // árbol
    gestor.Agregar(Dibujo(25, 3, arbol1, ftxui::Color::Green));       // árbol
    gestor.Agregar(Dibujo(40, 5, arbol1, ftxui::Color::Green));       // árbol
    gestor.Agregar(Dibujo(8, 10, jugador1, ftxui::Color::Magenta));    // jugador1
    gestor.Agregar(Dibujo(20, 11, jugador2, ftxui::Color::Yellow));   // jugador2 
    gestor.Agregar(Dibujo(5, 15, jugador3, ftxui::Color::Red));       // jugador3 
    gestor.Agregar(Dibujo(25, 13, jugador4, ftxui::Color::Green));    // jugador4
    gestor.Agregar(Dibujo(30, 8, jugador5, ftxui::Color::Blue));      // jugador5
    gestor.Agregar(Dibujo(10, 6, arbitro, ftxui::Color::Yellow));  // arbitro random


    Corral corral(50, 5, 30, 14, ftxui::Color::White);
    corral.AgregarAnimal(Dibujo(67, 7, jugador1, ftxui::Color::Orange));
    corral.AgregarAnimal(Dibujo(60, 9, jugador2, ftxui::Color::Yellow));
    corral.AgregarAnimal(Dibujo(53, 13, jugador6, ftxui::Color::White)); // jugador6

    int frames = 120;
    for (int frame = 0; frame < frames; ++frame)
    {
        screen.Clear();

        gestor.dibujos[5].x = 8 + (frame % 10);   // jugador1  derecha
        gestor.dibujos[6].x = 20 - (frame % 10);  // jugador2 izquierda
        gestor.dibujos[9].x = 30 + (frame % 15);  // jugador5derecha
        gestor.dibujos[7].x = 5 + (frame % 12);   // jugador3 horizontal

        int Jugador6_x = 53 + ((frame %70) - 10);
        Corral corral_frame(50, 5, 30, 14, ftxui::Color::White);
        corral_frame.AgregarAnimal(Dibujo(67, 7, jugador1, ftxui::Color::Cyan));
        corral_frame.AgregarAnimal(Dibujo(60, 9, jugador2, ftxui::Color::Yellow));
        corral_frame.AgregarAnimal(Dibujo(Jugador6_x, 13, jugador6, ftxui::Color::White));

        gestor.DibujarTodos(screen);
        corral_frame.Dibujar(screen);

        std::cout << screen.ToString();
        std::cout << screen.ResetPosition();
        std::cout << std::flush;

        std::this_thread::sleep_for(std::chrono::milliseconds(120));
    }


    return 0;
}
