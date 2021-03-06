// Licensed to the Apache Software Foundation (ASF) under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.

#pragma once

#include <memory>
#include <string>
#include "server/delivery/request/BaseRequest.h"

namespace milvus {
namespace server {

class DropPartitionRequest : public BaseRequest {
 public:
    static BaseRequestPtr
    Create(const std::shared_ptr<Context>& context, const std::string& table_name, const std::string& partition_name,
           const std::string& tag);

 protected:
    DropPartitionRequest(const std::shared_ptr<Context>& context, const std::string& table_name,
                         const std::string& partition_name, const std::string& tag);

    Status
    OnExecute() override;

 private:
    const std::string table_name_;
    const std::string partition_name_;
    const std::string tag_;
};

}  // namespace server
}  // namespace milvus
