enum type {
    EM,  // electromechanical
    SS,  // solid state
};

struct pinmachine_machine {
    char name[40];
    int year;
    int players;
    enum type type;
};
