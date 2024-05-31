// Default abstract contract for crude oil and gold future contract specification
// Minimum tick 0.0001 and the tick dollar valye 0.0001
#ifndef __Spec_h__
#define __Spec_h__

namespace PPBOOK {

    class SpecDefault {
    public:
        static const char* name(){return "default";}
        static double tick(){return 0.0001;}
        static double tickValue(){return 0.0001;}
    };
// Gold COMEX Exhange
    class SpecGC {
    public:
        static const char* name(){return "GC";}
        static double tick(){return 0.1;}
        static double tickValue(){return 10.0;}
    };
// Crude Oil NY Mercantile Exchange
    class SpecCO {
    public:
        static const char* name(){return "S";}
        static double tick(){return 0.25;}
        static double tickValue(){return 12.5;}
    };
//…
} // PPBOOK
#endif /* __Spec_h__ */