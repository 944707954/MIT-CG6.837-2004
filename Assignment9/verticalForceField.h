#pragma once
#include "forceField.h"

class VerticalForceField :public ForceField {
public:
	VerticalForceField(float magnitude);
	virtual ~VerticalForceField();

	// ͨ�� ForceField �̳�
	virtual Vec3f getAcceleration(const Vec3f& position, float mass, float t) const override;
private:
	float magnitude;
};