#include<iostream>
#include<SFML/Network.hpp>
#include<conio.h>
using namespace std;

int main()
{
    sf::IpAddress ip = sf::IpAddress::getLocalAddress();
    sf::TcpSocket socket;
    size_t received;
    char buffer[2000];
    
    socket.connect(ip, 2000);
    string text;
    text = "Sunt un client nou.";
    socket.send(text.c_str(), text.length() + 1);
    while (true)
    { 
        int alegere;
        cout << "0. logare\n";
        cout << "1. inregistrare\n";
        cout << "2. istoric apel -> administrator\n";
        cout << "3. istoric apel -> un utilizator\n";
        cout << "4. istoric dispecer fara detalii\n";
        cout << "5. adaug detalii si mut din asteptare in istoric\n";
        cout << "6. istoric apeluri dispecer\n";
        cout << "7. afiseaza toti utilizatorii pt dispecer\n";
        cout << "8. intoarce istoric apeluri admin\n";
        cout << "9. stergere dispecer\n";
        cout << "10. adaugare dispecer\n";
        cout << "11. inregistrari utilizatori in asteptare\n";
        cout << "12. aprobare inregistrare\n";
        cout << "13. respinge inregistrare\n";
        cout << "14. sterge utilizatorul\n";
        cout << "15. respingere cerere stergere utilizator\n";
        cout << "Alege protocolul: ";

        cin >> alegere;

        switch (alegere) {
            case 0: {
                //0. logare
                //text = "0$elena321$parolaelena$";
                text = "0$elena123$parolaelena$";
                break;
            }
            case 1: {
                //1. inregistrare
                text = "1$daria$paroladaria$Dariaa$Daria$nsfvspes@gmail.com$0747778001$";
                //text = "1$elena123$parolaelena$Tepes$Elena$elena_ruxandra@yahoo.com$0752551224$" ;
                break;
            }
            case 2: {
                //2. istoric apel -> administrator
                text = "2$elena123$dispecer1$10.05.2022 18:22:08$10.05.2022 18:23:00$fisier1$";
                //text = "2$elena123$dispecer2$10.05.2022 14:02:08$10.05.2022 14:07:01$fisier2$";
                //text = "2$elena123$dispecer1$11.05.2022 5:12:08$11.05.2022 5:17:01$fisier3$";
                //text = "2$ana_otilia$dispecer1$10.05.2022 7:12:22$10.05.2022 7:35:10$fisier4$";
                break;
            }
            case 3: {
                //3. istoric apel -> un utilizator
                text = "3$elena123$";
                //text = "3$ana_otilia$";
                //text = "3$ana$"; //daca nu este corect mesajul
                break;
            }
            case 4: {
                //4. istoric dispecer fara detalii
                text = "4$dispecer1$";
                break;
            }
            case 5: {
                //5. adaug detalii si mut din asteptare in istoric
                text = "5$dispecer1$1$fara detalii$";
                break;
            }
            case 6: {
                //6.istoric apeluri dispecer -> username_client$data+timp$detalii$fisier_audio$
                text = "6$dispecer1$";
                break;
            }
            case 7: {
                //7.afiseaza toti utilizatorii pt dispecer -> username$nume$prenume$email$telefon$*
                text = "7$";
                break;
            }
            case 8: {
                //8. intoarce istoric apeluri admin
                text = "8$";
                break;
            }
            case 9: {
                //9. stergere dispecer
                text = "9$dispecer1$";
                break;
            }
            case 10: {
                //10. adaugare dispecer
                text = "10$dispecer3$parola$blablablatralala_email@blabla.com$nume3$prennume3$Pompieri$0000000003$";
                break;
            }
            case 11: {
                //11.inregistrari utilizatori in asteptare
                text = "11$";
                break;
            }
            case 12: {
                //12. aproba inregistrarea
                text = "12$anastasia$";
                break;
            }
            case 13: {
                //13. respinge inregistrare
                text = "13$maria$";
                break;
            }
            case 14: {
                //14. sterge utilizatorul
                text = "14$utilizator2$";
                break;
            }
            case 15: {
                //15.respingere cerere stergere utilizator 
                text = "15$utilizator1$";
                break;
            }
            default:
                continue;
        }
        socket.send(text.c_str(), text.length() + 1);

        socket.receive(buffer, sizeof(buffer), received);
        if (received > 0)
            cout << buffer << endl;
        if (buffer == "v")
            cout << "S-a efectuat cu succes" << endl;
    }
}