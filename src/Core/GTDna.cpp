// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#include "Core/GTDna.h"
#include "Utils/GTUtils.h"

using namespace std;
using namespace sf;
using namespace ssvu;
using namespace ssvuj;
using namespace sses;
using namespace ssvs;
using namespace ssvs::Utils;
using namespace ssvsc;
using namespace ssvsc::Utils;

namespace gt
{
	GTGene::GTGene(float mTime, float mDegrees, float mMagnitude) : time{mTime}, velocity{getVectorFromDegrees(mDegrees, mMagnitude)} { }
	GTDna::GTDna(vector<GTGene>& mGenes) : genes{mGenes} { }
	GTOrganism::GTOrganism(GTDna mDna) : dna{mDna} { }

	GTDna GTDna::crossover(const GTDna& mOther)
	{
		vector<GTGene> resultGenes;

		for(unsigned int i{0}; i < genes.size(); ++i)
		{
			if(i % 2 == 0) resultGenes.push_back(genes[i]);
			else resultGenes.push_back(mOther.genes[i]);
		}

		return GTDna{resultGenes};
	}
	void GTDna::mutate(float mMutationRate) { for(unsigned int i{0}; i < genes.size(); ++i) if(getRnd(0, 100) < mMutationRate) genes[i] = getRandomGene(); }

	GTPopulation::GTPopulation(float mMutationRate, unsigned int mOrganismCount) : mutationRate{mMutationRate}
	{
		for(unsigned int i{0}; i < mOrganismCount; ++i) organisms.push_back(getRandomOrganism());
	}

	float GTPopulation::getMinFitness()
	{
		float result{numeric_limits<float>::max()};
		for(const auto& o : organisms) if(o->fitness < result) result = o->fitness;
		return result;
	}
	float GTPopulation::getMedianFitness()
	{
		float result{0};
		for(const auto& o : organisms) result += o->fitness;
		return result / organisms.size();
	}
	float GTPopulation::getMaxFitness()
	{
		float result{0};
		for(const auto& o : organisms) if(o->fitness > result) result = o->fitness;
		return result;
	}

	void GTPopulation::selection()
	{
		matingPool.clear();
		float maxFitness{getMaxFitness()};

		//sort(begin(organisms), end(organisms), [](GTOrganism* a, GTOrganism* b){ return a->fitness < b->fitness; });
		//matingPool.push_back(organisms[0]);
		//return;

		for(const auto& o : organisms)
		{
			float fitnessNormal{getMapped<float>(o->fitness, 0.f, getClamped(maxFitness, 0.f, 999.f), 0.f, 1.f)};

			int n{static_cast<int>(pow((1 - fitnessNormal), bias) * (150 * (bias * 2)))};
			n = max(1, n);
			for(int i{0}; i < n; ++i) matingPool.push_back(o);
		}
	}

	void GTPopulation::reproduction()
	{
		vector<GTOrganism*> newOrganisms;

		for(unsigned int i{0}; i < organisms.size(); ++i)
		{
			int m{getRnd(0, matingPool.size() - 1)};
			int d{getRnd(0, matingPool.size() - 1)};

			GTOrganism& mother(*matingPool[m]);
			GTOrganism& father(*matingPool[d]);

			GTDna childDna{mother.dna.crossover(father.dna)};
			childDna.mutate(mutationRate);

			newOrganisms.push_back(new GTOrganism{childDna});
		}

		for(const auto& o : organisms) delete o;
		organisms = newOrganisms;
		++generation;
	}

	int GTPopulation::getGeneration() { return generation; }

	GTGene getRandomGene()
	{
		float time{static_cast<float>(getRnd(0, 60))};
		float degrees{static_cast<float>(getRnd(0, 360))};
		float magnitude{static_cast<float>(getRnd(-25, 125))};
		return GTGene{time, degrees, magnitude};
	}
	GTDna getRandomDna(unsigned int mGeneCount)
	{
		vector<GTGene> genes;
		for(unsigned int i{0}; i < mGeneCount; ++i) genes.push_back(getRandomGene());
		return GTDna{genes};
	}
	GTOrganism* getRandomOrganism() { return new GTOrganism{getRandomDna(450)}; }
}
