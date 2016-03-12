#include "option.h"

spnp::Option::Option()
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

    //discret //based on simulation method
    //first 2
    outputUsual = true;
    //last 2
    //TODO
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
    n->setAttribute("outputUsual", this->outputUsual);

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
    this->outputUsual = xml->getAttributeB("outputUsual");
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
