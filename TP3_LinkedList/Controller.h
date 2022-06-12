int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);
int controller_loadFlyCodeFromText(char* path , LinkedList* pArrayListFlyCodes);
int controller_loadTypePassengerFromText(char* path , LinkedList* pArrayTypePassengers);
int controller_loadStatusPassengerFromText(char* path , LinkedList* pArrayStatusPassengers);
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);
int controller_addPassenger(LinkedList* pArrayListPassenger);
int controller_editPassenger(LinkedList* pArrayListPassenger);
int controller_removePassenger(LinkedList* pArrayListPassenger);
void selectPage(LinkedList* pArrayListPassenger, int option, int* inicio, int* final, int* flag);
void showFromTo(LinkedList* pArrayListPassenger);
void listPassenger(LinkedList* pArrayListPassenger);
int controller_ListPassenger(LinkedList* pArrayListPassenger);
int controller_ListFlyCodes(LinkedList* pArrayListFlyCodes);
int controller_ListTypePassengers(LinkedList* pArrayTypePassengers);
int controller_ListStatus(LinkedList* pArrayStatusPassengers);
int controller_sortPassenger(LinkedList* pArrayListPassenger);
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);


