#include <memory>   // for make_shared
#include <utility>  // for move

#include "ftxui/dom/elements.hpp"        // for Element, bold
#include "ftxui/dom/node.hpp"            // for Node
#include "ftxui/dom/node_decorator.hpp"  // for NodeDecorator
#include "ftxui/screen/box.hpp"          // for Box
#include "ftxui/screen/screen.hpp"       // for Pixel, Screen

namespace ftxui {

namespace {

}  // namespace

/// @brief Used inside a `frame`, this force the view to be scrolled toward a
/// a given position. The position is expressed in proportion of the requested
/// size.
/// 
/// For instance:
/// - (0, 0) means that the view is scrolled toward the upper left.
/// - (1, 0) means that the view is scrolled toward the upper right.
/// - (0, 1) means that the view is scrolled toward the bottom left.
/// @ingroup dom
///
/// ### Example
///
/// ```cpp
/// Element document = huge_document()
///   | focusPositionRelative(0.f, 1.f)
///   | frame;
/// ```
Decorator focusPositionRelative(float x, float y) {
  class Impl : public NodeDecorator {
   public:
    Impl(Element child, float x, float y)
        : NodeDecorator(child), x_(x), y_(y) {}

    void ComputeRequirement() override {
      NodeDecorator::ComputeRequirement();
      requirement_.selection = Requirement::Selection::NORMAL;

      Box& box = requirement_.selected_box;
      box.x_min = requirement_.min_x * x_;
      box.y_min = requirement_.min_y * y_;
      box.x_max = requirement_.min_x * x_;
      box.y_max = requirement_.min_y * y_;
    }

   private:
    const float x_;
    const float y_;
  };

  return [x, y](Element child) {
    return std::make_shared<Impl>(std::move(child), x, y);
  };
}

/// @brief Used inside a `frame`, this force the view to be scrolled toward a
/// a given position. The position is expressed in the numbers of cells.
/// 
/// @ingroup dom
///
/// ### Example
///
/// ```cpp
/// Element document = huge_document()
///   | focusPosition(10, 10)
///   | frame;
/// ```
Decorator focusPosition(int x, int y) {
  class Impl : public NodeDecorator {
   public:
    Impl(Element child, float x, float y)
        : NodeDecorator(child), x_(x), y_(y) {}

    void ComputeRequirement() override {
      NodeDecorator::ComputeRequirement();
      requirement_.selection = Requirement::Selection::NORMAL;

      Box& box = requirement_.selected_box;
      box.x_min = x_;
      box.y_min = y_;
      box.x_max = x_;
      box.y_max = y_;
    }

   private:
    const int x_;
    const int y_;
  };

  return [x, y](Element child) {
    return std::make_shared<Impl>(std::move(child), x, y);
  };
}

}  // namespace ftxui

// Copyright 2020 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.
