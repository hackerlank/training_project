#ifndef OPTION_H
#define OPTION_H

#include "abstractdata.h"

namespace spnp
{
class SPNPCLASSES_PUBLIC Option : public AbstractData
{
public:
    enum AnalysisOptions
    {
        STEADY_STATE,
        TRANSIENT,
        BOTH
    };
    enum Approach
    {
        CTMC,
        DTMC
    };
    enum SteadStateMethod
    {
        SUCCESSIVE_OVER_RELAXATION,
        GAUSS_SEIDEL,
        POWER
    };
    enum TransientMethod
    {
        STANDART_UNIFORMIZATION,
        FOX_GLYNN
    };

    enum VanishingMarkings
    {
        DURING_CONSTRUCTION,
        CONSIDERED_ORDINARY,
        BEFORE_CTMC
    };

    enum SimulationMethod
    {
        DISCRET_EVENT_INDEPENDENT,
        DISCRET_EVENT_BATCH,
        RESTART,
        SPLITTING
    };

    enum RequiredConfidence
    {
        PERC_90,
        PERC_95,
        PERC_99
    };

    Option();
    ~Option();

    virtual XMLNode* toXML();
    virtual void fromXML(XMLNode *xml);

    virtual std::string c_str(IData* data=nullptr) const;

    /* option files */
    bool isNumericalAnalysis;
    //output
    bool reachabilityGraphSet;
    bool markovChain;
    bool derivativeOfCTMC;
    bool probabilities;
    bool probabilitiesDTMC;
    bool dotGraphLanguage;

    /* numerical analysis */
    Option::AnalysisOptions analysis;
    bool sensitivity;
    //stop condition
    bool absorbinMarking;
    bool trasientVanishingLoops;
    bool transientInitialMarking;
    bool vanishingInitialMarking;
    //solution
    Option::Approach approach;
    Option::SteadStateMethod steadyStateMethod;
    Option::TransientMethod transientMethod;
    int maxIterations;
    double minPrecision;
    double m0returnRate;
    bool computeCumulativePRobabilities;
    bool steadyStateDetection;
    //elimination
    Option::VanishingMarkings vanishing;

    /* simulation */
    Option::SimulationMethod simulationMethod;
    bool isReplication;
    double replicationOrErrorValue;
    Option::RequiredConfidence confidence;
    double lengthSimulation;
    double fluidPlacesContent;
    double firingTimeConflict;
    double seed;
    bool printReport;

    //discret //based on simulation method
    //first 2
    bool outputUsual;
    //last 2
    //TODO
    virtual std::string getClassNodeName();
};
}

#endif // OPTION_H
