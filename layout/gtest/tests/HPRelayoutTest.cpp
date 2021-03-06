/* Tencent is pleased to support the open source community by making Hippy available.
 * Copyright (C) 2018 THL A29 Limited, a Tencent company. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <gtest.h>
#include <Hippy.h>

//TEST(HippyTest, dont_cache_computed_flex_basis_between_layouts) {
//
//
//  const HPNodeRef root = HPNodeNew();
//  HPNodeStyleSetHeightPercent(root, 100);
//  HPNodeStyleSetWidthPercent(root, 100);
//
//  const HPNodeRef root_child0 = HPNodeNew();
//  HPNodeStyleSetFlexBasisPercent(root_child0, 100);
//  HPNodeInsertChild(root, root_child0, 0);
//
//  HPNodeDoLayout(root, 100, VALUE_UNDEFINED);
//  HPNodeDoLayout(root, 100, 100);
//
//  ASSERT_FLOAT_EQ(100, HPNodeLayoutGetHeight(root_child0));
//
//  HPNodeFreeRecursive(root);
//
//
//}

TEST(HippyTest, recalculate_resolvedDimonsion_onchange) {
  const HPNodeRef root = HPNodeNew();

  const HPNodeRef root_child0 = HPNodeNew();
  HPNodeStyleSetMinHeight(root_child0, 10);
  HPNodeStyleSetMaxHeight(root_child0, 10);
  HPNodeInsertChild(root, root_child0, 0);

  HPNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);
  ASSERT_FLOAT_EQ(10, HPNodeLayoutGetHeight(root_child0));

  HPNodeStyleSetMinHeight(root_child0, VALUE_UNDEFINED);
  HPNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, HPNodeLayoutGetHeight(root_child0));

  HPNodeFreeRecursive(root);
}
