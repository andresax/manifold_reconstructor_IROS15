/*
 * PointsParserFromOut.h
 *
 *  Created on: 15/apr/2015
 *      Author: andrea
 */

#ifndef CAM_PARSERS_POINTSPARSERFROMOUT_H_
#define CAM_PARSERS_POINTSPARSERFROMOUT_H_
#include <string>

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include <glm/glm.hpp>

/*Reads a .out file similar to those generated by bundler, but without the cameras informations*/
class PointsParserFromOut {
public:
  PointsParserFromOut(const std::string path, int imageW = 0, int imageH = 0);
  virtual ~PointsParserFromOut();
  void parse(bool filterUnstable =true);

  const std::vector<glm::vec3>& getPoints() const {
    return points_;
  }

  const std::vector<std::vector<int> >& getCamViewingPointN() const {
    return camViewingPointN_;
  }
  const std::vector<int >& getCamViewingPointN(int idxpoint) const {
    return camViewingPointN_[idxpoint];
  }

  const std::vector<std::vector<int> >& getPointsVisibleFromCamN() const {
    return pointsVisibleFromCamN_;
  }

  const std::vector<int> & getPointsVisibleFromCamN(int idxCam) const {
    return pointsVisibleFromCamN_[idxCam];
  }

  std::vector<std::vector<glm::vec2> >& getPoint2DoncamViewingPoint()  {
    return point2DoncamViewingPoint_;
  }

private:

  std::vector<glm::vec3> points_;
  int numPoints_;
  std::ifstream fileStream_;
  std::vector<std::vector<int> > camViewingPointN_;
  std::vector<std::vector<int> > pointsVisibleFromCamN_;
  std::vector<std::vector<glm::vec2> > point2DoncamViewingPoint_;

  int imageWidth_, imageHeight_;
};

#endif /* CAM_PARSERS_POINTSPARSERFROMOUT_H_ */
