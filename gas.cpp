//=========================================================//
///Jalankan di CMD lebih bagus (Code Block atau yang lain)///
//=========================================================//

//============================================================================================//
///No text delay kalau di vscode, kalau tau caranya.. ubah saja (padahal dulu di python bisa)///
//============================================================================================//

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <chrono>
#include <thread>
#include <unistd.h>
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
using namespace std;

class Player{
    public:

    int def = 25;
    int level = 1;
    int EXP = 0;
    int hp = 100;
    int damage;

    string nama;
    string job;
    string listJob[3] = {"Ksatria", "Penyihir", "Pemanah"};
    
    void inputPemain(){
        cout << "Masukkan nama: ";
        getline(cin, nama);
        if (nama.empty()) {
            return inputPemain();
        }
    }

    void pilihJob(){
        int jobnya;
        cout << RED << "Pilih job/kelas:\n1. Ksatria\n2. Penyihir\n3. Pemanah\n" << RESET;

        do {
            cout << "Pilih job/kelas mu " << nama << ": ";
            cin >> jobnya;
            jobnya -= 1;
        } while (debruyne(listJob[jobnya]) || jobnya < 0 || jobnya > 2);
        
        job = listJob[jobnya];
        
        switch (jobnya) {
        
            case 0:
                hp += 100;
                def += 75;
                break;
            case 1:
                damage += 50;
                break;
            case 2:
                def += 25;
            default:
                break;
        }
        string blank;
        getline(cin, blank);
    }

    bool debruyne(string pilihan) {
        if (pilihan != listJob[0] && pilihan != listJob[1] && pilihan != listJob[2]) {
            cout << "Masukkan pilihan yang benar\n";
            return true;
        } else {
            return false;
        }
    }

};Player player;

class Story {
    public:
    int delay = 10000;
    int delay2 = 700000;
    int i;

    void enter (){
        cout << "\n\nTekan enter untuk melanjutkan...";
        cin.get();
        system("cls || clear");
    }

    void tampilkanText(const string& text, int d) {
        for (size_t i = 0; i < text.length(); i++) {
            cout << YELLOW << text[i] << RESET;
            usleep(d);
        }
        cout << endl;
    }

    //========//
    ///Prolog///
    //========//
    void Story1 (){
        
        string texts1[] = {
            "Di sebuah dunia yang dipenuhi dengan makhluk ajaib dan kekuatan kuno, terdapat sebuah akademi legendaris yang terletak di puncak gunung tertinggi.",
            "Akademi ini hanya menerima murid-murid yang memiliki potensi luar biasa dalam seni bela diri dan sihir.",
            "Setiap tahun, ribuan pemuda dari seluruh negeri berjuang untuk mendapatkan tempat di akademi tersebut, namun hanya sedikit yang berhasil.",
        };
        string texts2[] = {
            "Di desa yang jauh dari keramaian, hiduplah seorang pemuda yang penuh tekad.",
            "Sejak kecil, pemuda ini bermimpi untuk menjadi bagian dari akademi legendaris dan mengungkap rahasia yang tersembunyi di balik tembok-temboknya.",
            "Pemuda ini menghabiskan setiap hari berlatih keras, mempelajari seni bela diri dan sihir dari buku-buku yang ditinggalkan oleh kakeknya, seorang mantan murid akademi."
        };
        string texts3[] = {
            "Suatu hari, pemuda ini menerima surat undangan dari akademi.",
            "Dengan penuh semangat dan keberanian, ia berangkat meninggalkan desanya menuju akademi legendaris.",
            "Di sana, ia bertemu dengan teman-teman baru yang memiliki impian yang sama, serta guru-guru yang bijaksana dan kuat.",
            "Namun, perjalanan untuk menjadi yang terbaik tidaklah mudah.",
            "Pemuda ini harus menghadapi berbagai ujian yang menguji kemampuan, keberanian, dan tekadnya."
        };
        string texts4[] = {
            "Di tengah-tengah pelatihannya, pemuda ini menyadari bahwa ada kekuatan gelap yang mengancam dunia.",
            "Dengan bantuan teman-teman dan guru-gurunya, ia bertekad untuk melawan kekuatan tersebut dan melindungi dunia dari kehancuran.",
            "Petualangan besar ini tidak hanya akan menguji kemampuan fisiknya, tetapi juga kekuatan hatinya."
        };
        string texts5[] = {
            "Dan pemuda itu berama",
            "....."
        };
        string dot = ".....";

        //=========//
        ///Texts 1///
        //=========//
        for (const auto& text : texts1) {
            tampilkanText(text, delay);
            enter();
        }
        for (size_t i = 0; i < dot.length(); i++) {
            cout << YELLOW << dot[i] << RESET;
            usleep(delay2);
        }
        enter();

        //=========//
        ///Texts 2///
        //=========//
        for (const auto& text : texts2) {
            tampilkanText(text, delay);
            enter();
        }
        for (size_t i = 0; i < dot.length(); i++) {
            cout << YELLOW << dot[i] << RESET;
            usleep(delay2);
        }
        enter();

        //=========//
        ///Texts 3///
        //=========//
        for (const auto& text : texts3) {
            tampilkanText(text, delay);
            enter();
        }
        for (size_t i = 0; i < dot.length(); i++) {
            cout << YELLOW << dot[i] << RESET;
            usleep(delay2);
        }
        enter();

        //=========//
        ///Texts 4///
        //=========//
        for (const auto& text : texts4) {
            tampilkanText(text, delay);
            enter();
        }
        for (size_t i = 0; i < dot.length(); i++) {
            cout << YELLOW << dot[i] << RESET;
            usleep(delay2);
        }
        enter();

        //=========//
        ///Texts 5///
        //=========//
        for (const auto& text : texts5) {
            tampilkanText(text, delay);
            enter();
        }
        enter();

    }
}story;


int main(){
    string blank;
    system("cls || clear");

    sf::RenderWindow window(sf::VideoMode(800, 600), "Anime Latar");

    sf::Texture texture;
    if (!texture.loadFromFile("./assets/isekai-academy-background-less-colour (1).jpg")) {
        return -1;
    }

    sf::Sprite sprite;
    sprite.setTexture(texture);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }

    story.Story1();
    player.inputPemain();
    player.pilihJob();
}
