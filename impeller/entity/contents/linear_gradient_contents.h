// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#pragma once

#include <functional>
#include <memory>
#include <vector>

#include "flutter/fml/macros.h"
#include "impeller/entity/contents/color_source_contents.h"
#include "impeller/entity/entity.h"
#include "impeller/geometry/color.h"
#include "impeller/geometry/path.h"
#include "impeller/geometry/point.h"

namespace impeller {

class LinearGradientContents final : public ColorSourceContents {
 public:
  LinearGradientContents();

  ~LinearGradientContents() override;

  // |Contents|
  bool Render(const ContentContext& renderer,
              const Entity& entity,
              RenderPass& pass) const override;

  void SetEndPoints(Point start_point, Point end_point);

  void SetColors(std::vector<Color> colors);

  void SetTileMode(Entity::TileMode tile_mode);

  const std::vector<Color>& GetColors() const;

 private:
  Point start_point_;
  Point end_point_;
  std::vector<Color> colors_;
  Entity::TileMode tile_mode_;

  FML_DISALLOW_COPY_AND_ASSIGN(LinearGradientContents);
};

}  // namespace impeller
