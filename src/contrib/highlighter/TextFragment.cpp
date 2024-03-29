/////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2009-2014 Alan Wright. All rights reserved.
// Distributable under the terms of either the Apache License (Version 2.0)
// or the GNU Lesser General Public License.
/////////////////////////////////////////////////////////////////////////////

#include "ContribInc.h"
#include "TextFragment.h"

namespace Lucene {

TextFragment::TextFragment(const StringBufferPtr& markedUpText, int32_t textStartPos, int32_t fragNum) {
	this->markedUpText = markedUpText;
	this->textStartPos = textStartPos;
	this->textEndPos = 0;
	this->fragNum = fragNum;
	this->score = 0;
}

TextFragment::~TextFragment() {
}

void TextFragment::setScore(double score) {
	this->score = score;
}

double TextFragment::getScore() {
	return score;
}

void TextFragment::merge(const TextFragmentPtr& frag2) {
	textEndPos = frag2->textEndPos;
	score = std::max(score, frag2->score);
}

bool TextFragment::follows(const TextFragmentPtr& fragment) {
	return (textStartPos == fragment->textEndPos);
}

int32_t TextFragment::getFragNum() {
	return fragNum;
}

String TextFragment::toString() {
	return markedUpText->toString().substr(textStartPos, textEndPos - textStartPos);
}

StringBuffer::~StringBuffer() {
}

int32_t StringBuffer::length() const
{
	return _length;
}

String StringBuffer::toString() {
	return buffer.str();
}

void StringBuffer::append(const String& str) {
	buffer << str;
	_length += str.length();
}

void StringBuffer::append(const wchar_t& c)
{
	buffer << c;
	++_length;
}

void StringBuffer::clear() {
	buffer.str(L"");
	_length = 0;
}

}
