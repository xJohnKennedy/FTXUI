#include <ftxui/dom/elements.hpp>  // for text, operator|, vbox, border, Element, Fit, hbox
#include <ftxui/screen/screen.hpp>  // for Full, Screen
#include <memory>                   // for allocator

#include "ftxui/dom/flexbox_config.hpp"  // for ftxui
#include "ftxui/dom/node.hpp"            // for Render

int main(int argc, const char* argv[]) {
  using namespace ftxui;
  auto document =  //
      hbox({
          vbox({
              text("Line 1"),
              text("Line 2"),
              text("Line 3"),
          }) | border,

          vbox({
              text("Line 4"),
              text("Line 5"),
              text("Line 6"),
          }) | border,

          vbox({
              text("Line 7"),
              text("Line 8"),
              text("Line 9"),
          }) | border,
      });
  auto screen = Screen::Create(Dimension::Full(), Dimension::Fit(document));
  Render(screen, document);
  screen.Print();
}

// Copyright 2020 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.
