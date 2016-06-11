#include "option.h"

spnp::Option::Option():AbstractData()
{
    /* option files */
    //output
    isNumericalAnalysis = true;
    reachabilityGraphSet = false;
    markovChain = false;
    derivativeOfCTMC = false;
    probabilities = false;
    probabilitiesDTMC = false;
    dotGraphLanguage = false;

    /* numerical analysis */
    analysis = Option::AnalysisOptions::STEADY_STATE;
    sensitivity = false;
    //stop condition
    absorbinMarking = false;
    trasientVanishingLoops = false;
    transientInitialMarking = true;
    vanishingInitialMarking = true;
    //solution
    approach = Option::Approach::CTMC;
    steadyStateMethod = Option::SteadStateMethod::SUCCESSIVE_OVER_RELAXATION;
    transientMethod = Option::TransientMethod::FOX_GLYNN;
    maxIterations = 2000;
    minPrecision = 0.000001;
    m0returnRate = 0.0;
    computeCumulativeProbabilities = true;
    steadyStateDetection = true;
    //elimination
    vanishing = Option::VanishingMarkings::DURING_CONSTRUCTION;

    /* simulation */
    simulationMethod = Option::SimulationMethod::DISCRET_EVENT_INDEPENDENT;
    isReplication = true;
    replicationOrErrorValue = 0;
    confidence = Option::RequiredConfidence::PERC_90;
    lengthSimulation = 0.0;
    fluidPlacesContent = 0.000001;
    firingTimeConflict = 0.000001;
    seed = 52836;
    printReport = false;

    warmup = 0.0;

    //discret //based on simulation method
    //first 2
    outputUsual = true;
    //last 2
    isFinishEach = false;
    numPreSim = 10;
    isPreSim = true;
    numImport = 6;

    a1="";
    a2="";
    a3="";
    a4="";
    a5="";
    a6="";

    //split
    stopNum = 60;
    numPreSimB = 10;
    isPreSimB = true;
    numImportB = 6;

    b1="";
    b2="";
    b3="";
    b4="";
    b5="";
    b6="";
}

spnp::Option::~Option()
{

}

XMLNode *spnp::Option::toXML()
{
    XMLNode* n = AbstractData::toXML();

    n->setAttribute("isNumericalAnalysis", this->isNumericalAnalysis);
    n->setAttribute("reachabilityGraphSet", this->reachabilityGraphSet);
    n->setAttribute("markovChain", this->markovChain);
    n->setAttribute("derivativeOfCTMC", this->derivativeOfCTMC);
    n->setAttribute("probabilities", this->probabilities);
    n->setAttribute("probabilitiesDTMC", this->probabilitiesDTMC);
    n->setAttribute("dotGraphLanguage", this->dotGraphLanguage);
    n->setAttribute("analysis", static_cast<int>(this->analysis));
    n->setAttribute("sensitivity", this->sensitivity);
    n->setAttribute("absorbinMarking", this->absorbinMarking);
    n->setAttribute("trasientVanishingLoops", this->trasientVanishingLoops);
    n->setAttribute("transientInitialMarking", this->transientInitialMarking);
    n->setAttribute("vanishingInitialMarking", this->vanishingInitialMarking);
    n->setAttribute("approach", static_cast<int>(this->approach));
    n->setAttribute("steadyStateMethod", static_cast<int>(this->steadyStateMethod));
    n->setAttribute("transientMethod", static_cast<int>(this->transientMethod));
    n->setAttribute("maxIterations", this->maxIterations);
    n->setAttribute("minPrecision", this->minPrecision);
    n->setAttribute("m0returnRate", this->m0returnRate);
    n->setAttribute("computeCumulativeProbabilities", this->computeCumulativeProbabilities);
    n->setAttribute("steadyStateDetection", this->steadyStateDetection);
    n->setAttribute("vanishing", static_cast<int>(this->vanishing));
    n->setAttribute("simulationMethod", static_cast<int>(this->simulationMethod));
    n->setAttribute("isReplication", this->isReplication);
    n->setAttribute("replicationOrErrorValue", this->replicationOrErrorValue);
    n->setAttribute("confidence", static_cast<int>(this->confidence));
    n->setAttribute("lengthSimulation", this->lengthSimulation);
    n->setAttribute("fluidPlacesContent", this->fluidPlacesContent);
    n->setAttribute("firingTimeConflict", this->firingTimeConflict);
    n->setAttribute("seed", this->seed);
    n->setAttribute("printReport", this->printReport);
    n->setAttribute("warmup", this->warmup);
    n->setAttribute("outputUsual", this->outputUsual);

    n->setAttribute("isFinishEach", this->isFinishEach);
    n->setAttribute("numPreSim", this->numPreSim);
    n->setAttribute("isPreSim", this->isPreSim);
    n->setAttribute("numImport", this->numImport);

    n->setAttribute("a1", this->a1);
    n->setAttribute("a2", this->a2);
    n->setAttribute("a3", this->a3);
    n->setAttribute("a4", this->a4);
    n->setAttribute("a5", this->a5);
    n->setAttribute("a6", this->a6);

    n->setAttribute("stopNum", this->stopNum);
    n->setAttribute("numPreSimB", this->numPreSimB);
    n->setAttribute("isPreSimB", this->isPreSimB);
    n->setAttribute("numImportB", this->numImportB);

    n->setAttribute("b1", this->b1);
    n->setAttribute("b2", this->b2);
    n->setAttribute("b3", this->b3);
    n->setAttribute("b4", this->b4);
    n->setAttribute("b5", this->b5);
    n->setAttribute("b6", this->b6);

    return n;
}

void spnp::Option::fromXML(XMLNode *xml)
{
    AbstractData::fromXML(xml);
    this->isNumericalAnalysis = xml->getAttributeB("isNumericalAnalysis");
    this->reachabilityGraphSet = xml->getAttributeB("reachabilityGraphSet");
    this->markovChain = xml->getAttributeB("markovChain");
    this->derivativeOfCTMC = xml->getAttributeB("derivativeOfCTMC");
    this->probabilities = xml->getAttributeB("probabilities");
    this->probabilitiesDTMC = xml->getAttributeB("probabilitiesDTMC");
    this->dotGraphLanguage = xml->getAttributeB("dotGraphLanguage");
    this->analysis = static_cast<AnalysisOptions>(xml->getAttributeI("analysis"));
    this->sensitivity = xml->getAttributeB("sensitivity");
    this->absorbinMarking = xml->getAttributeB("absorbinMarking");
    this->trasientVanishingLoops = xml->getAttributeB("trasientVanishingLoops");
    this->transientInitialMarking = xml->getAttributeB("transientInitialMarking");
    this->vanishingInitialMarking = xml->getAttributeB("vanishingInitialMarking");
    this->approach = static_cast<Approach>(xml->getAttributeI("approach"));
    this->steadyStateMethod = static_cast<SteadStateMethod>(xml->getAttributeI("steadyStateMethod"));
    this->transientMethod = static_cast<TransientMethod>(xml->getAttributeI("transientMethod"));
    this->maxIterations = xml->getAttributeI("maxIterations");
    this->minPrecision = xml->getAttributeD("minPrecision");
    this->m0returnRate = xml->getAttributeD("m0returnRate");
    this->computeCumulativeProbabilities = xml->getAttributeB("computeCumulativeProbabilities");
    this->steadyStateDetection = xml->getAttributeB("steadyStateDetection");
    this->vanishing = static_cast<VanishingMarkings>(xml->getAttributeI("vanishing"));
    this->simulationMethod = static_cast<SimulationMethod>(xml->getAttributeI("simulationMethod"));
    this->isReplication = xml->getAttributeB("isReplication");
    this->replicationOrErrorValue = xml->getAttributeD("replicationOrErrorValue");
    this->confidence = static_cast<RequiredConfidence>(xml->getAttributeI("confidence"));
    this->lengthSimulation = xml->getAttributeD("lengthSimulation");
    this->fluidPlacesContent = xml->getAttributeD("fluidPlacesContent");
    this->firingTimeConflict = xml->getAttributeD("firingTimeConflict");
    this->seed = xml->getAttributeD("seed");
    this->printReport = xml->getAttributeB("printReport");
    this->warmup = xml->getAttributeD("warmup");
    this->outputUsual = xml->getAttributeB("outputUsual");

    this->isFinishEach = xml->getAttributeB("isFinishEach");
    this->numPreSim = xml->getAttributeI("numPreSim");
    this->isPreSim = xml->getAttributeB("isPreSim");
    this->numImport = xml->getAttributeI("numImport");

    this->a1 = xml->getAttributeS("a1");
    this->a2 = xml->getAttributeS("a2");
    this->a3 = xml->getAttributeS("a3");
    this->a4 = xml->getAttributeS("a4");
    this->a5 = xml->getAttributeS("a5");
    this->a6 = xml->getAttributeS("a6");

    this->stopNum = xml->getAttributeI("stopNum");
    this->numPreSimB = xml->getAttributeI("numPreSimB");
    this->isPreSimB = xml->getAttributeB("isPreSimB");
    this->numImportB = xml->getAttributeI("numImportB");

    this->b1 = xml->getAttributeS("b1");
    this->b2 = xml->getAttributeS("b2");
    this->b3 = xml->getAttributeS("b3");
    this->b4 = xml->getAttributeS("b4");
    this->b5 = xml->getAttributeS("b5");
    this->b6 = xml->getAttributeS("b6");
}

std::string spnp::Option::c_str(spnp::IData *data) const
{
    /*(void)data;
    std::stringstream ss;
    ss << "place(\"" << getName() << "\");\n";
    if(this->tokens.compare("0")!=0)
    {
        ss<< "init(\"" << getName() << "\"," << this->tokens << ");\n";
    }
    return ss.str();*/
}

std::string spnp::Option::getClassNodeName()
{
    return "option";
}
