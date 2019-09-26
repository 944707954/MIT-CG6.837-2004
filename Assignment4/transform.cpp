#include "transform.h"

Transform::Transform(Matrix &m, Object3D *o) {
	obj = o;
	matrix = m;
}
Transform::~Transform() {

}
bool Transform::intersect(const Ray &r, Hit &h, float tmin) {
	bool flag = false;
	Vec3f origin = r.getOrigin();
	Vec3f direction = r.getDirection();
	Matrix invM = matrix;

	if (invM.Inverse()) {
		invM.Transform(origin);
		invM.TransformDirection(direction);
		//direction.Normalize();Ϊʲô���ܵ�λ��
		Ray ray2(origin, direction);
		flag = obj->intersect(ray2, h, tmin);
		if (flag) {
			Vec3f n = h.getNormal();
			Matrix invMT = invM;
			invMT.Transpose();
			invMT.TransformDirection(n);
			n.Normalize();
			h.set(h.getT(), h.getMaterial(), n, r);//ע����r
		}
	}
	return flag;
}

void Transform::paint() {
	glPushMatrix();
	GLfloat *glMatrix = matrix.glGet();
	glMultMatrixf(glMatrix);
	delete[] glMatrix;
	obj->paint();
	glPopMatrix();
}