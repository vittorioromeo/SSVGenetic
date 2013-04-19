#ifndef SSVGT_CORE_DNA
#define SSVGT_CORE_DNA

#include "Core/GTDependencies.h"

namespace gt
{
	struct GTGene
	{
		float time;
		sf::Vector2f velocity;

		GTGene(float mTime, float mDegrees, float mMagnitude);
	};

	struct GTDna
	{
		std::vector<GTGene> genes;

		GTDna(std::vector<GTGene>& mGenes);

		GTDna crossover(const GTDna& mOther);
		void mutate(float mMutationRate);
	};

	struct GTOrganism
	{
		GTDna dna;
		float fitness{0};

		GTOrganism(GTDna mDna);
	};

	struct GTPopulation
	{
		float mutationRate, bias{4};
		std::vector<GTOrganism*> organisms, matingPool;
		int generation{0};

		GTPopulation(float mMutationRate, unsigned int mOrganismCount);

		void selection();
		void reproduction();

		void setBias(float mBias);
		void setMutationRate(float mMutationRate);

		float getMinFitness();
		float getMedianFitness();
		float getMaxFitness();
		int getGeneration();
	};

	GTGene getRandomGene();
	GTDna getRandomDna(unsigned int mGeneCount);
	GTOrganism* getRandomOrganism();
}

#endif
