//
//  main.cpp
//  Connexion
//
//  Created by Jalel Benerrami on 26/02/2016.
//  Copyright © 2016 Jalel Benerrami. All rights reserved.
//


#include "Tools.h"
#include "Point2D.h"
#include "Simulation.h"
#include "CmdLine.h"


int main(int argc, const char * argv[]) {
    
    
//    /*
//       Run programm by choosing parameters into the IDE
//    */
//    srand((unsigned int)time(0));
//
//    // Number of random points
//    int n;
//    cout << "Enter the number of points you want to generate : ";
//    cin >> n;
//    cout << endl;
//    
//    // Width and height of the display window
//    int w,h;
//    cout << "Enter values of width and height of display window : \n"
//    << "width = ";
//    cin >> w;
//    cout << "height = ";
//    cin >> h;
//    cout << endl;
//    
//    // Choose a strategy
//    int s;
//    cout << "Choose a strategy : ";
//    cin >> s;
//    cout << endl;
//    
//    // Create a simulation with given number of points, width and height
//    Simulation Sim = Simulation(n, w, h);
//    
//    // Execute the created simulation
//    Sim.execute(s);
//    
//    // Display the information about executed simulation
//    cout << Sim1;
//    cout << endl;
//    
//    // Click on the window to close it
//    endGraphics();
//    cout << endl;
    
    
    
    
    /*
       Run programm by command line in a terminal
    */
    
    srand((unsigned int)time(0));
    
    bool help, version, informations;
    int number = 2000; // while we don't enter an other number argument, variable number stays equal to 2000
    int width = 700, length = 700; // display window's default size
    int strategy = 1; // first strategy run by default
    
    // Define a CmdLine instance
    command::CmdLine cmd;
    // Complete the vector opt with options
    cmd.add( command::make_option('h', "help", help) );
    cmd.add( command::make_option('v', "version", version) );
    cmd.add( command::make_option('i', "informations", informations) );
    cmd.add( command::make_option('n', "number", number) );
    cmd.add( command::make_option('w', "width", width) );
    cmd.add( command::make_option('l', "length", length) );
    cmd.add( command::make_option('s', "stategy", strategy) );
    
    // show which arguments have been entered
    for(int i=1; i<argc; i++){
        cout << "argument " << i << ": " << argv[i] << endl;
    }
    cout << endl;
    
    // decode arguments and check options
    try{
        cmd.process(argc, argv);
    }catch(string s){
        cout << s << endl;
        return 1;
    }
    
    // allow the user to know which options are possible
    if(help){
        cout << "-h, --help: print usage informations" << endl;
        cout << "-v, --version: print version" << endl;
        cout << "-n, --number: choose the number of generated random points" << endl;
        cout << "-w, --width: choose the display window's width (interval of possible abscissas)" << endl;
        cout << "-l, --length: choose the display window's height (interval of possible ordinates)" << endl;
        cout << "-s, --strategy: choose the connexion strategy" << endl;
        cout << endl;
    }
    
    
    // indicate the programm's version
    if(version){
        cout << "programm Connexion : version 2.19" << endl;
        cout << endl;
    }
    
    
    // indicate the programm's informations
    if(informations){
        cout << "Université Paris-Diderot" << endl;
        cout << "Master 1 Mathématiques" << endl;
        cout << "Projet probabilités et statistiques 2015/2016" << endl;
        cout << "Connexion optimale d'un ensemble aléatoire de points" << endl;
        cout << "Etudiants : BENERRAMI Jalel / CAVICCHI Vincent" << endl;
        cout << "Encadrants : Aurélie Fischer / Justin Salez" << endl;
        cout << endl;
    }
    
    
    // indicate that the programm has built and run right but no option has been entered
    if(!help && !version && !informations && number == 2000 && width == 700 && length == 700 && strategy == 1){
        cout << "Build succeeded with default parameters ; no option entered." << endl;
        cout << endl;
    }
    
    // Create a simulation with given number of points, width and height
    Simulation Sim = Simulation(number, width, length);
    
    // Execute the created simulation
    Sim.execute(strategy);
    
    // Display the information about executed simulation
    cout << Sim;
    cout << endl;

    // Click on the window to close it
    endGraphics();
    cout << endl;
    
    return 0;
}
