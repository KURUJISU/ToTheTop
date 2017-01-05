
#include "precompiled.h"


Block::Block() {
	name_ = "Block";
	size_ = ofVec2f(120, 50);
	pos_ = ofVec3f(ofGetWindowWidth() / 2, -size_.y);
	vel_ = ofVec3f(0, 50.0f);

	virtualPos_ = pos_;
}

void Block::setup() {
	enableUpdate();
}

void Block::update(float deltaTime) {
	virtualPos_.y += vel_.y * deltaTime;
	if ((virtualPos_.y - pos_.y) >= size_.y) {
		pos_ = virtualPos_;
	}
}

void Block::draw() {
	ofSetColor(ofColor(255, 0, 0));
	ofDrawRectangle(getRectangle());
}