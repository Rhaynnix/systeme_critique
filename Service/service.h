#include <pthread.h>
#include <mutex>
#include "../Watchdog/watchdog.h"
#include "../Capteur_Buffer/capteur.h"
#include "../SMemory/SMemory.h"
#include "../Capteur_Buffer/circular_buffer.h"

using namespace std;

class Service {

protected:
	int timeout_;
	mutex* le_mutex_;
	float valeur_capteur_;
	int ancien_watchdog_;
	float res_;
        char mode_;          // primary / backup

        Watchdog* WD_;    // pointeur (reference) sur (adresse du) watchdog
        Capteur* CP_;        // pointeur (reference) sur (adresse du) capteur
        SMemory* ME_;    // pointeur (reference) sur (adresse de) memoire stable
        Circular_Buffer* pCBUF_;    // pointeur sur un buffer circulaire


public:
        Service (char, Watchdog*, Capteur*, SMemory*, Circular_Buffer*, mutex*) ;
        void run () ;
	float calcul(Circular_Buffer* buf);
	void runPrimary();
	void runBackup();
};

