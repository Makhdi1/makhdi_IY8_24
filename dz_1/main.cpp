#include "BSTree.h"

#include <iostream>
#include <limits>
#include <sstream>


int main() {
    simplebst::BSTree tree;

    std::cout << "Choose mode:\n";
    std::cout << "1 - use example numbers\n";
    std::cout << "2 - enter numbers manually\n";
    std::cout << "Your choice: ";

    int choice;
    std::cin >> choice;


    if (choice == 1) {
        // Пример
        tree.add(50);
        tree.add(30);
        tree.add(70);
        tree.add(20);
        tree.add(40);
        tree.add(60);
        tree.add(80);


        std::cout<<"Tree in order: "<< tree<< std::endl;


        std::cout <<"Pre-order: ";
        tree.printPreOrder();

        std::cout <<"In-order: ";
        tree.printInOrder();

        std::cout <<"Post-order: ";
        tree.printPostOrder();


        std::cout <<"Contains 40? " <<(tree.contains(40) ? "Yes" : "No ") <<std::endl;
        std::cout <<"Contains 100? " <<(tree.contains(100) ? "Yes" : "No ") <<std::endl;


        tree.remove(30);
        std::cout <<"After remving 30, in-order: ";
        tree.printInOrder();


        tree.saveToFile("tree.txt");
        std::cout <<"Tree saved to tree.txt" <<std::endl;

        simplebst::BSTree tree2;
        tree2.loadFromFile("tree.txt");
        std::cout <<"Loaded tree from file, in-order: " <<tree2 <<std::endl;


        simplebst::BSTree tree3 = tree;
        std::cout <<"Copied tree (tree3): " <<tree3 <<std::endl;


        simplebst::BSTree tree4 = std::move(tree3);
        std::cout << "Moves tree (tree4): " <<tree4 <<std::endl;
        std::cout << "Tree3 after move (should be empty): " << tree3 << std::endl;



        return 0;
    }




    // Свои числа
    if (choice == 2) {
        std::cout <<"Enter numbers (one per line, -1 to finish): \n";

        int num;
        while (true) {
            std::cin >>num;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout <<"That's not a number, stopping input.\n ";
                break;
            }

            if (num == -1) break;

            tree.add(num);
        }


        std::cout << "\nChoose command mode:\n";
        std::cout << "1 - all commands at once (batch)\n";
        std::cout << "2 - interactive menu\n";
        std::cout << "Your choice: ";

        int cmdMode;
        std::cin >> cmdMode;


        if (cmdMode == 1) {
            // Batch

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout <<"Available commands: add <N>, remove <N>, search <N>,\n";
            std::cout<<"preorder, inorder, postorder, print, clear, save <file>, load <file>, copymove, exit\n";
            std::cout <<"Enter your commands in one line: ";

            std::string line;
            std::getline(std::cin,line);
            std::istringstream iss(line);
            std::string cmd;

            while (iss >> cmd) {

                if (cmd == "add") {
                    int val;
                    if (iss >> val) tree.add(val);
                    else std::cout <<"add: missiing number\n";

                } else if (cmd =="remove") {
                    int val;
                    if (iss >>val) tree.remove(val);
                    else std::cout <<"remove: missing number\n";

                } else if (cmd =="search") {
                    int val;
                    if (iss >>val) {
                        std::cout << "Search " <<val << ": "
                                  <<(tree.contains(val) ? "found" : "not found") << std::endl;
                    } else std::cout <<"search: miissing number\n";

                } else if (cmd =="preorder") {
                    std::cout << "Pre-order: ";
                    tree.printPreOrder();

                } else if (cmd== "inorder") {
                    std::cout <<"In-order: ";
                    tree.printInOrder();

                } else if (cmd =="postorder") {
                    std::cout <<"Post-order: ";
                    tree.printPostOrder();

                } else if (cmd== "print") {
                    std::cout <<"Tree: " << tree << std::endl;

                } else if (cmd== "clear") {
                    tree.clear();
                    std::cout<< "Tree clearef.\n";

                } else if (cmd =="save") {
                    std::string fname;
                    if (iss >>fname) tree.saveToFile(fname);
                    else std::cout <<"save: missing filenamw\n";

                } else if (cmd == "load") {
                    std::string fname;
                    if (iss >>fname) tree.loadFromFile(fname);
                    else std::cout <<"load: missing filename\n";

                } else if (cmd =="copymove") {
                    std::cout <<"--- Copy and Move demo ---\n";
                    simplebst::BSTree copyTree =tree;
                    std::cout <<"Copied tree: " <<copyTree <<std::endl;
                    simplebst::BSTree moveTree =std::move(copyTree);
                    std::cout <<"Moved tree: " <<moveTree <<std::endl;
                    std::cout <<"Source after move: " <<copyTree <<std::endl;

                } else if (cmd == "exit") {
                    break;

                } else {
                    std::cout << "Unknown command: " <<cmd <<std::endl;
                }
            }
            return 0;
        } else {
            // Интерактивчик
            int menuChoice =0;
            int value;
            std::string filename;

            while (menuChoice != 12) {

                std::cout << "\n--- Tree Menu ---\n";
                std::cout << "1. Add number \n";
                std::cout << "2. Remove number \n";
                std::cout << "3. Search number \n";
                std::cout << "4. Print pre-order\n";
                std::cout << "5. Print in-order\n";
                std::cout << "6. Print post-order\n";
                std::cout << "7. Print tree  (operator<<)\n";
                std::cout << "8. Clear tree\n";
                std::cout << "9. Save to file\n";
                std::cout << "10. Load from file \n";
                std::cout << "11. Copy and Move demo \n";
                std::cout << "12. Exit \n";
                std::cout << "Choose: ";
                std::cin >> menuChoice;

                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input, try again .\n";
                    continue;
                }

                switch (menuChoice) {

                    case 1:
                        std::cout <<"Number to add: ";
                        std::cin >>value;
                        tree.add(value);

                        break;

                    case 2:

                        std::cout << "Number to remove : ";
                        std::cin >>value;
                        tree.remove(value);
                        break;


                    case 3:

                        std::cout <<"Number to search: ";
                        std::cin >> value;

                        if (tree.contains(value))
                            std::cout <<value <<" is in the tree.\n";
                        else
                            std::cout << value <<" not found.\n";
                        break;


                    case 4:

                        std::cout << "Pre-order: ";
                        tree.printPreOrder();
                        break;


                    case 5:

                        std::cout <<"In-order: ";
                        tree.printInOrder();
                        break;


                    case 6:

                        std::cout <<"Post-order: ";
                        tree.printPostOrder();
                        break;


                    case 7:

                        std::cout <<"Tree (in-order): " <<tree <<std::endl;
                        break;


                    case 8:

                        tree.clear();
                        std::cout <<"Tree cleared.\n";
                        break;


                    case 9:

                        std::cout <<"File name to save: ";
                        std::cin>> filename;
                        tree.saveToFile(filename);
                        break;


                    case 10:

                        std::cout <<"File name to load: ";
                        std::cin >>filename;
                        tree.loadFromFile(filename);
                        break;

                    case 11: {

                        std::cout << "\n--- Copy and Move demo ---\n";
                        simplebst::BSTree copyTree = tree;
                        std::cout << "Copied tree (in-order): " << copyTree << std::endl;
                        simplebst::BSTree moveTree = std::move(copyTree);
                        std::cout << "Moved tree (in-order): " << moveTree << std::endl;
                        std::cout << "Source after move (should be empty): " << copyTree << std::endl;
                        break;

                    }


                    case 12:
                        std::cout <<"Poka Poka!\n";
                        break;

                    default:
                        std::cout << "Wrong option.\n";
                }
            }
        }
    }

    return 0;
}
