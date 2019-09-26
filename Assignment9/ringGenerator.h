#pragma once
#include "generator.h"

class RingGenerator :public Generator {
public:
	RingGenerator(float position_randomness, Vec3f velocity, float velocity_randomness);
	virtual ~RingGenerator();

	// ͨ�� Generator �̳�
	virtual int numNewParticles(float current_time, float dt) const override;
	virtual Particle* Generate(float current_time, int i) override;
	virtual void Paint() const override;
private:
	float position_randomness;
	Vec3f velocity;
	float velocity_randomness;

	
};