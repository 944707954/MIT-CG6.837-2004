#pragma once
#include "forceField.h"

class RadialForceField :public ForceField {

public:
	RadialForceField(float magnitude);
	virtual ~RadialForceField();



	// ͨ�� ForceField �̳�
	virtual Vec3f getAcceleration(const Vec3f& position, float mass, float t) const override;

private:
	float magnitude;
};